#!/usr/bin/env python3
"""Test suite for push_swap and checker: error handling, every ordering of
1 to 5 numbers, random runs of 100 and 500 numbers checked against the
benchmark limits, and a Valgrind pass when it is installed.

Every output is verified by ./checker and, if present, by 42's checker_linux.
Exits with status 1 if any check fails."""

import argparse
import itertools
import os
import random
import shutil
import statistics
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
INT_MIN, INT_MAX = -2**31, 2**31 - 1

# Limits from the evaluation sheet (3 and 5 numbers) and the subject
# (fewer than 700 for 100 numbers, no more than 5500 for 500)
SMALL_LIMITS = {3: 3, 5: 12}
RANDOM_SIZES = ((100, 700, "<"), (500, 5500, "<="))

ERROR_CASES = (
    ("not a number", ["0", "one", "2", "3"]),
    ("trailing letters", ["1", "2a", "3"]),
    ("duplicate", ["1", "1"]),
    ("0 and -0", ["0", "-0"]),
    ("above INT_MAX", ["2147483648"]),
    ("below INT_MIN", ["-2147483649"]),
    ("beyond long", ["99999999999999999999"]),
    ("tab separator", ["1\t2"]),
    ("empty string", [""]),
)
SILENT_CASES = (
    ("no argument", []),
    ("one number", ["42"]),
    ("already sorted", ["1", "2", "3", "4", "5", "6"]),
)
SORT_CASES = (
    ("INT_MIN and INT_MAX", ["2147483647", "-2147483648"]),
    ("quoted and separate", ["3 2 1", "0"]),
    ("signs", ["+5", "-3", "0"]),
)
CHECKER_CASES = (
    ("valid solution", ["3", "2", "1", "0"], "rra\npb\nsa\nrra\npa\n", "OK\n", ""),
    ("wrong solution", ["3", "2", "1", "0"], "sa\nrra\npb\n", "KO\n", ""),
    ("no instruction, sorted", ["1", "2", "3"], "", "OK\n", ""),
    ("no instruction, unsorted", ["2", "1"], "", "KO\n", ""),
    ("unknown instruction", ["1", "2"], "xx\n", "", "Error\n"),
    ("trailing space", ["2", "1"], "sa \n", "", "Error\n"),
    ("upper case", ["2", "1"], "SA\n", "", "Error\n"),
    ("invalid argument", ["3", "2", "one", "0"], "sa\n", "", "Error\n"),
    ("no argument", [], "", "", ""),
)


class Suite:
    def __init__(self, push_swap, checkers):
        self.push_swap = push_swap
        self.checkers = checkers
        self.passed = 0
        self.failed = 0

    def report(self, label, detail, ok):
        print(f"  {label:<26}{detail:<64}{'OK' if ok else 'FAILED'}")
        if ok:
            self.passed += 1
        else:
            self.failed += 1

    def run(self, nums):
        """Sort nums, verify the output with every checker, return the
        number of operations and whether all checkers printed OK."""
        args = [str(x) for x in nums]
        out = subprocess.run([self.push_swap] + args, capture_output=True,
                             text=True).stdout
        ok = all(subprocess.run([c] + args, input=out, capture_output=True,
                                text=True).stdout == "OK\n"
                 for c in self.checkers)
        return out.count("\n"), ok


def show(args):
    return " ".join(repr(a) if not a or " " in a or "\t" in a else a
                    for a in args)


def test_errors(s):
    print("Error handling")
    for label, args in ERROR_CASES:
        r = subprocess.run([s.push_swap] + args, capture_output=True, text=True)
        s.report(label, show(args), r.stdout == "" and r.stderr == "Error\n")
    for label, args in SILENT_CASES:
        r = subprocess.run([s.push_swap] + args, capture_output=True, text=True)
        s.report(label, show(args) or "(none)",
                 r.stdout == "" and r.stderr == "")
    for label, args in SORT_CASES:
        _, ok = s.run(args)
        s.report(label, show(args), ok)


def test_checker(s, checker):
    print("\nChecker")
    for label, args, stdin, out, err in CHECKER_CASES:
        r = subprocess.run([checker] + args, input=stdin, capture_output=True,
                           text=True)
        s.report(label, show(args) or "(none)",
                 r.stdout == out and r.stderr == err)


def test_small(s, pool):
    print("\nSmall inputs, every ordering")
    for n in range(1, 6):
        orders = list(itertools.permutations(range(n)))
        results = list(pool.map(s.run, orders))
        counts = [c for c, _ in results]
        sorted_ok = sum(ok for _, ok in results)
        limit = SMALL_LIMITS.get(n)
        ok = sorted_ok == len(orders) and (limit is None or max(counts) <= limit)
        detail = (f"{sorted_ok:>4} / {len(orders):<4} sorted   "
                  f"avg {statistics.mean(counts):>6.1f}   worst {max(counts):>5}"
                  + (f"   limit {limit}" if limit else ""))
        s.report(f"{n} number{'s' if n > 1 else ''}", detail, ok)


def test_random(s, pool, rng, runs):
    print("\nRandom inputs, values across the whole int range")
    for (n, limit, op), count in zip(RANDOM_SIZES, runs):
        inputs = [rng.sample(range(INT_MIN, INT_MAX + 1), n) for _ in range(count)]
        results = list(pool.map(s.run, inputs))
        counts = [c for c, _ in results]
        sorted_ok = sum(ok for _, ok in results)
        within = sum(c < limit if op == "<" else c <= limit for c in counts)
        avg = statistics.mean(counts)
        ok = sorted_ok == count and (avg < limit if op == "<" else avg <= limit)
        detail = (f"{sorted_ok:>4} / {count:<4} sorted   avg {avg:>6.0f}   "
                  f"worst {max(counts):>5}   {100 * within / count:.1f}% {op} {limit}")
        s.report(f"{n} numbers", detail, ok)
        for (c, good), nums in zip(results, inputs):
            if not good:
                print(f"    first unsorted input: {' '.join(map(str, nums))}")
                break


def test_memory(s, checker, rng):
    print("\nMemory")
    valgrind = shutil.which("valgrind")
    if not valgrind:
        print("  skipped: valgrind is not installed")
        return
    args = [str(x) for x in rng.sample(range(INT_MIN, INT_MAX + 1), 500)]
    vg = [valgrind, "--leak-check=full", "--errors-for-leak-kinds=all",
          "--error-exitcode=42", "-q"]
    r = subprocess.run(vg + [s.push_swap] + args, capture_output=True, text=True)
    s.report("push_swap", "500 numbers: no leak, no memory error",
             r.returncode == 0)
    r = subprocess.run(vg + [checker] + args, input=r.stdout,
                       capture_output=True, text=True)
    s.report("checker", "500 numbers: no leak, no memory error",
             r.returncode == 0 and r.stdout == "OK\n")


def main():
    parser = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    parser.add_argument("--push-swap", default=os.path.join(ROOT, "push_swap"),
                        help="push_swap binary to test (default: ./push_swap)")
    parser.add_argument("--checker", default=os.path.join(ROOT, "checker"),
                        help="checker binary to test and use (default: ./checker)")
    parser.add_argument("--seed", type=int, default=42,
                        help="random seed (default: 42, the README's figures)")
    parser.add_argument("--runs", type=int, nargs=2, default=(1000, 300),
                        metavar=("N100", "N500"),
                        help="random runs of 100 and 500 numbers (default: 1000 300)")
    opts = parser.parse_args()

    for path in (opts.push_swap, opts.checker):
        if not os.access(path, os.X_OK):
            sys.exit(f"{path} not found: run make bonus first")
    checkers = [opts.checker]
    reference = os.path.join(ROOT, "checker_linux")
    if sys.platform.startswith("linux") and os.access(reference, os.X_OK):
        checkers.append(reference)

    s = Suite(opts.push_swap, checkers)
    rng = random.Random(opts.seed)
    print(f"Seed {opts.seed}, outputs verified by "
          f"{' and '.join(os.path.basename(c) for c in checkers)}\n")
    with ThreadPoolExecutor(max_workers=os.cpu_count() or 4) as pool:
        test_errors(s)
        test_checker(s, opts.checker)
        test_small(s, pool)
        test_random(s, pool, rng, opts.runs)
    test_memory(s, opts.checker, rng)

    total = s.passed + s.failed
    if s.failed:
        print(f"\n{s.failed} of {total} checks FAILED")
        sys.exit(1)
    print(f"\nAll {total} checks passed")


if __name__ == "__main__":
    main()
