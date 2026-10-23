_This project has been created as part of the 42 curriculum by flomulle._

# PUSH_SWAP

## Description

Push_Swap is a 42 School algorithm project that challenges you to sort data on a stack with a limited set of instructions, using two stacks (A and B) and the lowest possible number of operations. The goal is to write a C program that calculates and displays the most efficient sequence of operations to sort a list of integers.

### Key Concepts

- Sorting algorithm optimization

- Stack operations with constrained moves

- Algorithm complexity analysis

- Performance optimization for large datasets

### Project Goals

- Implement an efficient sorting algorithm using only two stacks

- Handle both small (3-5 numbers) and large (100-500 numbers) datasets

- Minimize the number of operations for optimal sorting

- Learn about algorithm complexity and performance analysis

## Instructions

### Prerequisites

- Clang compiler

- GNU Make

- Basic understanding of stack data structures and sorting algorithms

### Compilation

1. Clone the repository:

```
bash
git clone
cd push_swap
```

2. Build the main program:

```
bash

make
```

This compiles the push_swap executable.

3. Build the bonus checker:
```
bash

make bonus
```
This compiles the checker executable for validating sort sequences.

4. Clean build files:
```
bash

make clean		# Remove object files
make fclean		# Remove object files and executables
make re			# Rebuild from scratch
```

### Usage

**Basic Usage**

Generate random numbers and sort them\
`./push_swap 4 67 3 87 23`

Use with random number generator\
`ARG="4 67 3 87 23"; ./push_swap $ARG`

Check the number of operations\
`ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l`

**Checker (Bonus)**

Check if operations correctly sort the list\
`ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG`

**Performance Testing**

Generate 500 random numbers\
`seq 1 500 | shuf | tr '\n' ' '`

Test with 500 numbers\
`ARG=$(seq 1 500 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l`

Test and check with 500 numbers\
`ARG=$(seq 1 500 | shuf | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG`

### Expected Performance

- 100 numbers: Less than 700 operations

- 500 numbers: Less than 5500 operations

## Algorithm Overview

Available Operations

- sa/sb/ss: Swap first two elements

- pa/pb: Push from one stack to another

- ra/rb/rr: Rotate stack upward

- rra/rrb/rrr: Rotate stack downward

**Sorting Strategy**

- For Small Stacks (2-5 numbers)

	- Hardcoded optimal sequences

	- Pattern-based sorting

- For Large Stacks (100-500 numbers)

	- A slightly optimized chunk and a cheap algorithm:

		1. The numbers of stack a have been normalized from 0 to stack-size.

		2. Larger numbers, meaning superior to half of the size of the stack, are pushed to b, and small numbers are pushed to b then b is rotated to send them to the bottom of the stack.

		3. 5 numbers are kept in stack a, well splitted (1/5, 2/5, 3/5, 4/5 et largest number of stack a), they get sorted by the small stack algorithm.

		4. Then for each value in stack b, the cost to bring it to the top + the cost to bring its closest value in stack a to the top of stack + the cost to push and sort them is evaluated. The "cheapest" move is done, rinse and repeat.

		5. When b is empty, the smallest value (0) is brought to the top of stack a, and thus stack a is sorted.

## Project Structure
```
text
push_swap/
├── inc/				# Main header files
├── src/				# Main source files
├── inc_bonus/			# Bonus header files
├── src_bonus/			# Bonus source files
├── libft/				# Custom library
├── build/				# Compiled objects
├── build_bonus/		# Compiled bonus objects
├── Makefile			# Build system
└── README.md			# This file
```

## Resources
### Documentation & References

- 42 School Subject - Official project requirements

- Stacks - [Wikipedia](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))

- Analysis of algorithms - [Wikipedia](https://en.wikipedia.org/wiki/Analysis_of_algorithms)

- When in doubt : [Stackoverflow](https://stackoverflow.com)

- Looking for ideas : the 42 discord, related project channel
	- Specifically, the idea not to use linked lists and rather an array of ints, both because it makes more sense to work with stacks, it uses a lot less memory

### AI Usage Declaration

**This project was developed with the assistance DeepSeek**
Used for learning the basics of how it is possible for a program to catch user inputs (read(0) in a while (1)).
Why Deepseek ? I like reading the thinking process.

Absolutely no other AI has been used, not that it makes my project better, probably the opposite, but I learn a lot more and on the long term through struggling for hours and days, to find ideas and debbug my tries.

### Features and choices

- Core Features

	- ✅ Validation of input arguments (isint) and parsing in a structure containing a max size, a current size, a name and an array of int (the stack)

	- ✅ Clean memory management

	- ✅ Error handling for invalid inputs

	- ✅ Efficient sorting algorithm for varying input sizes

	- ✅ Optimization for minimal operation count

- Bonus Features (Checker)

	- ✅ Operation validation from standard input

	- ✅ Integration with push_swap program

	- ✅ Error checking for invalid operations

## License

**This project is developed as part of the 42 School curriculum. The code is intended for educational purposes and follows 42's norms and standards.**
