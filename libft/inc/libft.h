/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flomulle <flomulle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:25:18 by flomulle          #+#    #+#             */
/*   Updated: 2025/12/14 19:54:09 by flomulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
	HEADERS
*/
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

/*
	LIBC FUNCTIONS
*/

/**
 * Checks if a character is alphabetic.
 * Determines whether the given integer `c` corresponds to an ASCII
 * letter (either uppercase 'A'–'Z' or lowercase 'a'–'z').
 * @param {int} c - Character to test.
 * @returns {int} 1 if `c` is alphabetic, otherwise 0.
 */
int		ft_isalpha(int c);
/**
 * Checks if a character is a decimal digit.
 * Determines whether `c` belongs to the range '0'–'9'.
 * @param {int} c - Character to test.
 * @returns {int} 1 if `c` is a digit, otherwise 0.
 */
int		ft_isdigit(int c);
/**
 * @brief Checks if a string contains an int (accepts + and -)
 * @param {char *s} c - Character to test.
 * @returns {int} 1 if `s` is an int, otherwise 0.
 * @note uses ft_atol
 */
int		ft_isint(const char *s);
/**
 * Checks if a character is alphanumeric.
 * Returns true for ASCII letters and digits.
 * @param {int} c - Character to test.
 * @returns {int} 1 if `c` is alphanumeric, otherwise 0.
 */
int		ft_isalnum(int c);
/**
 * Checks whether a value is a valid ASCII code.
 * Valid ASCII codes are in the range 0–127.
 * @param {int} c - Value to test.
 * @returns {int} 1 if `c` is ASCII, otherwise 0.
 */
int		ft_isascii(int c);
/**
 * Checks if a character is printable.
 * Printable ASCII characters range from 32 to 126.
 * @param {int} c - Character to test.
 * @returns {int} 1 if printable, otherwise 0.
 */
int		ft_isprint(int c);
/**
 * Converts a lowercase character to uppercase.
 * @param {int} c - Character to convert.
 * @returns {int} Uppercase equivalent or `c` if not lowercase.
 */
int		ft_toupper(int c);
/**
 * Converts an uppercase character to lowercase.
 * @param {int} c - Character to convert.
 * @returns {int} Lowercase equivalent or `c` if not uppercase.
 */
int		ft_tolower(int c);
//
/**
 * Computes the length of a string.
 * Iterates over the characters of `s` until a null terminator is found.
 * @param {char*} s - Null-terminated string.
 * @returns {size_t} Number of characters before '\0'.
 */
size_t	ft_strlen(const char *s);
/**
 * Copies a string with size limitation.
 * Writes up to `dstsize - 1` characters and null-terminates.
 * Returns the length of `src`.
 * @param {char*} dst - Destination buffer.
 * @param {const char*} src - Source string.
 * @param {size_t} dstsize - Size of destination buffer.
 * @returns {size_t} Length of `src`.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize);
/**
 * Concatenates strings with size limitation.
 * Appends `src` to `dst` ensuring space for null terminator.
 * Returns length of the string it tried to create.
 * @param {char*} dst - Destination buffer.
 * @param {const char*} src - Source string.
 * @param {size_t} dstsize - Total size of destination buffer.
 * @returns {size_t} Length of initial dst + length of src.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dsize);
/**
 * Converts a string to an integer.
 * Handles optional whitespace, sign, and digit sequence.
 * Overflow behavior is undefined as in standard atoi.
 * @param {const char*} str - String containing number.
 * @returns {int} Parsed integer value.
 */
int		ft_atoi(const char *ptr);
/**
 * Converts a string to a long.
 * Handles optional whitespace, sign, and digit sequence.
 * Cam be used to avoid the overflow possible in the standard atoi.
 * @param {const char*} str - String containing number.
 * @returns {long} Parsed long value.
 */
long	ft_atol(const char *str);
/**
 * Searches for a character in a string.
 * Returns a pointer to the first occurrence of `c`
 * within the string `s`, or NULL if not found.
 * @param {const char*} s - String to search.
 * @param {int} c - Character to locate.
 * @returns {char*} Pointer to match or NULL.
 */
char	*ft_strchr(const char *s, int c);
/**
 * Searches for the last occurrence of a character in a string.
 * @param {const char*} s - String to search.
 * @param {int} c - Character to locate.
 * @returns {char*} Pointer to match or NULL.
 */
char	*ft_strrchr(const char *s, int c);
/**
 * Compares two strings for up to `n` characters.
 * @param {const char*} s1 - First string.
 * @param {const char*} s2 - Second string.
 * @param {size_t} n - Maximum number of bytes to compare.
 * @returns {int} Difference between first mismatched bytes.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/**
 * Locates a substring in a limited-length string.
 * Searches for the null-terminated substring `needle`
 * within the first `len` characters of `haystack`.
 * @param {const char*} big - String to search inside.
 * @param {const char*} little - Substring to find.
 * @param {size_t} len - Max search length.
 * @returns {char*} Pointer to first match or NULL.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);
/**
 * Duplicates a string.
 * Allocates memory and copies the content of `s1`.
 * @param {const char*} s1 - String to duplicate.
 * @returns {char*} Newly allocated copy of the string.
 */
char	*ft_strdup(const char *s);
//
/**
 * Allocates zero-initialized memory.
 * Allocates `count * size` bytes and sets them to zero.
 * @param {size_t} count - Number of elements.
 * @param {size_t} size - Size of each element.
 * @returns {void*} Pointer to allocated memory or NULL.
 */
void	*ft_calloc(size_t nmemb, size_t size);
/**
 * Sets a block of memory to zero.
 * Equivalent to calling memset(s, 0, n).
 * @param {void*} s - Memory area to zero.
 * @param {size_t} n - Number of bytes to clear.
 * @returns {void} Nothing.
 */
void	ft_bzero(void *s, size_t n);
/**
 * Fills a block of memory with a byte value.
 * Writes `c` to the first `n` bytes of memory pointed by `s`.
 * @param {void*} s - Destination memory.
 * @param {int} c - Value (converted to unsigned char).
 * @param {size_t} n - Number of bytes to write.
 * @returns {void*} Pointer to `s`.
 */
void	*ft_memset(void *s, int c, size_t n);
/**
 * Copies a block of memory.
 * Copies `n` bytes from `src` to `dst`. Undefined behavior if memory overlaps.
 * @param {void*} dst - Destination buffer.
 * @param {const void*} src - Source buffer.
 * @param {size_t} n - Number of bytes to copy.
 * @returns {void*} Pointer to `dst`.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);
/**
 * Safe memory copy with overlap handling.
 * Copies `n` bytes from `src` to `dst`, correctly handling overlapping regions.
 * @param {void*} dst - Destination buffer.
 * @param {const void*} src - Source buffer.
 * @param {size_t} n - Number of bytes to copy.
 * @returns {void*} Pointer to `dst`.
 */
void	*ft_memmove(void *dest, const void *src, size_t n);
/**
 * Scans memory for a byte value.
 * @param {const void*} s - Memory area.
 * @param {int} c - Byte to search for.
 * @param {size_t} n - Number of bytes to examine.
 * @returns {void*} Pointer to match or NULL.
 */
void	*ft_memchr(const void *s, int c, size_t n);
/**
 * Compares two memory blocks.
 * @param {const void*} s1 - First memory block.
 * @param {const void*} s2 - Second memory block.
 * @param {size_t} n - Number of bytes to compare.
 * @returns {int} Difference of first differing bytes.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*
	STRINGS
*/

/**
 * Extracts a substring from a string.
 * Allocates and returns up to `len` characters
 * from `s` starting at position `start`.
 * @param {const char*} s - Original string.
 * @param {unsigned int} start - Index of start.
 * @param {size_t} len - Max length of substring.
 * @returns {char*} New substring or empty string on error.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);
/**
 * Joins two strings into a new allocated string.
 * @param {const char*} s1 - Prefix string.
 * @param {const char*} s2 - Suffix string.
 * @returns {char*} Joined string.
 */
char	*ft_strjoin(char const *s1, char const *s2);
/**
 * Trims characters from the start and end of a string.
 * Removes all characters in `set` from both ends of `s1`.
 * @param {const char*} s1 - String to trim.
 * @param {const char*} set - Characters to remove.
 * @returns {char*} Trimmed string.
 */
char	*ft_strtrim(char const *s1, char const *set);
/**
 * @brief Count "words" delimited by a separator in a string.
 * @param s - String containing words
 * @param c - Separator between words
 * @return int
 */
int		ft_count_words(char const *s, char c);
/**
 * Splits a string by a delimiter into an array.
 * Allocates a NULL-terminated array containing the substrings
 * of `s` separated by the character `c`.
 * @param {const char*} s - String to split.
 * @param {char} c - Delimiter.
 * @returns {char**} Array of substrings or NULL.
 */
char	**ft_split(char const *s, char c);
/**
 * @brief Free a NULL terminated array of strings,
 * created with split for instance.
 * @param {char **s} - array of string, NULL terminated
 */
void	ft_free_array_strs(char **s);
/**
 * Converts an integer to a string.
 * Handles negative values and zero.
 * @param {int} n - Number to convert.
 * @returns { char * } - Numeric string representation.
 */
char	*ft_itoa(int n);
/**
 * Applies a function to each character of a string.
 * Builds a new string where each character is the result
 * of applying function `f` to `s[i]` and its index `i`.
 * @param {const char*} s - Input string.
 * @param {char(*)(unsigned int, char)} f - Callback function.
 * @returns {char*} New transformed string.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/**
 * Applies a function to each character of a string in-place.
 * @param {char*} s - String to modify.
 * @param {void(*)(unsigned int, char*)} f - Callback function.
 * @returns {void}
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/*
	OUTPUT
*/

/**
 * Writes a character to a file descriptor.
 * @param {char} c - Character to write.
 * @param {int} fd - File descriptor.
 */
void	ft_putchar_fd(char c, int fd);
/**
 * Writes a string to a file descriptor.
 * @param {const char*} s - String to write.
 * @param {int} fd - File descriptor.
 */
void	ft_putstr_fd(char *s, int fd);
/**
 * Writes a string followed by a newline to a file descriptor.
 * @param {const char*} s - String to write.
 * @param {int} fd - File descriptor.
 */
void	ft_putendl_fd(char *s, int fd);
/**
 * Writes a number to a file descriptor.
 * Converts the integer to its decimal representation.
 * @param {int} n - Number to write.
 * @param {int} fd - File descriptor.
 */
void	ft_putnbr_fd(int n, int fd);

/*
	LISTS
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
//
/**
 * Creates a new list element.
 * Allocates a new node whose `content` is set to `content`
 * and whose `next` pointer is initialized to NULL.
 * @param {void*} content - Content to store.
 * @returns {t_list*} New list node.
 */
t_list	*ft_lstnew(void *content);
/**
 * Adds a node at the beginning of a list.
 * @param {t_list**} lst - Address of list head.
 * @param {t_list*} new - Node to add.
 */
void	ft_lstadd_front(t_list **lst, t_list *new);
/**
 * Counts the number of elements in a list.
 * @param {t_list*} lst - List head.
 * @returns {int} Number of nodes.
 */
int		ft_lstsize(t_list *lst);
/**
 * Returns the last element of a list.
 * @param {t_list*} lst - List head.
 * @returns {t_list*} Last node or NULL.
 */
t_list	*ft_lstlast(t_list *lst);
/**
 * Adds a node at the end of a list.
 * @param {t_list**} lst - Address of list head.
 * @param {t_list*} new - Node to add.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);
/**
 * Deletes a single list node.
 * Uses function `del` to free the content,
 * then frees the node itself.
 * @param {t_list*} lst - Node to delete.
 * @param {void(*)(void*)} del - Cleanup function.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*));
/**
 * Deletes and frees all nodes of a list.
 * @param {t_list**} lst - Address of list head.
 * @param {void(*)(void*)} del - Content cleanup function.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*));
/**
 * Applies a function to each element's content.
 * @param {t_list*} lst - List head.
 * @param {void(*)(void*)} f - Function to apply.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));
/**
 * Creates a new list by applying a function to each element.
 * If allocation fails, the whole new list is freed using `del`.
 * @param {t_list*} lst - Original list.
 * @param {void*(*)(void*)} f - Transform function.
 * @param {void(*)(void*)} del - Cleanup function.
 * @returns {t_list*} Newly created transformed list.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*
	FT_PRINTF.c
*/
typedef struct s_format
{
	int			width;
	int			precision;
	int			minus;
	int			zero;
	int			dot;
	int			hash;
	int			space;
	int			plus;
	char		type;
}				t_format;

/**
 * Writes formatted output to standard output (stdout), similar to printf.
 * Supports format specifiers: %c, %s, %p, %d, %i, %u, %x, %X, and %%.
 * Handles flags, width and precision in the format string.
 * Returns the total number of characters written.
 * @param {const char*} format - Null-terminated format string
 * containing text and format specifiers.
 * @param {...} ... - Additional arguments corresponding to
 * format specifiers in `format`.
 * @returns {int} Total number of characters printed (excluding null-terminator),
 * or a negative value if an output error occurs.
 * @note
 */
int		ft_printf(const char *format, ...);

// FT_PARSING.c
int		ft_parse_specifier(const char **format, t_format *fmts);
void	ft_parse_precision(const char **format, t_format *fmts);
void	ft_parse_width(const char **format, t_format *fmts);
void	ft_parse_flags(const char **format, t_format *fmt);
int		ft_parse_format(const char *format, va_list args);

// FT_SPECIFIERS0.c
void	ft_init_fmts(t_format *fmts);
int		ft_specifiers(t_format *fmts, va_list args);

// FT_SPECIFIERS1.c
int		ft_spe_char(t_format *fmts, va_list args);
int		ft_spe_string(t_format *fmts, va_list args);
int		ft_spe_string_minus(t_format *fmts, va_list args);
int		ft_spe_pointer(t_format *fmts, va_list args);
int		ft_spe_pointer_minus(t_format *fmts, va_list args);

// FT_SPECIFIERS2.c
int		ft_spe_int(t_format *fmts, va_list args);
int		ft_spe_int_minus(t_format *fmts, va_list args);
int		ft_spe_uint(t_format *fmts, va_list args);
int		ft_spe_uint_minus(t_format *fmts, va_list args);

// FT_SPECIFIERS3.c
int		ft_spe_hexa(t_format *fmts, va_list args, int upcase);
int		ft_spe_hexa_minus(t_format *fmts, va_list args, int upcase);
int		ft_spe_percent(t_format *fmts);

// FT_SETTINGS.c
int		ft_width(int width, int minus, int zero, int *count);
int		ft_plus_space(t_format *fmts, int *count);
int		ft_int_sign(long n, t_format *fmts, int *count);
int		ft_int_precision(long n, t_format *fmts, int *count);
int		ft_hexa_uint_precision(unsigned int n, int upcase, t_format *fmts,
			int *count);

// FT_OUTPUT1.c
int		ft_putchar_count(char c, int *count);
int		ft_putstr_count(char *s, int slen, int *count);
int		ft_putnbr_count(long n, int *count);

// FT_OUTPUT2.c
int		ft_puthexa_count(unsigned long n, int upcase, int *count);
int		ft_puthexa_uint_count(unsigned int n, int upcase, int *count);
int		ft_put_hash_count(t_format *fmts, int *count);

// FT_UTILITIES1.c
int		ft_count_digits(long n, int base, t_format *fmts);
int		ft_count_udigits(unsigned long n, int base, t_format *fmts);
int		ft_max(int a, int b);
int		ft_min_if_pos(int a, int b);

// FT_UTILITIES2.c
int		ft_addressnull(t_format *fmts, int *count);
int		ft_ptrnull(t_format *fmts, int *count);

/*
	GET_NEXT_LINE
*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif
// get_next_line.c
char	*read_to_store(int fd, char *stash);
char	*extract_line(char *stash);
char	*clean_store(char *stash);
/**
 * Reads the next line from a file descriptor `fd`.
 * Supports reading from multiple file descriptors simultaneously (bonus).
 * Each call returns a newly allocated string ending with a newline character
 * if present.
 * The function maintains an internal static buffer for each file descriptor.
 * Returns NULL on end-of-file or error.
 * @param {int} fd - File descriptor to read from.
 * @returns {char*} Pointer to a newly allocated string containing the next line,
 * including the newline character if present. Returns NULL on EOF or error.
 * The caller is responsible for freeing the returned string.
 */
char	*ft_get_next_line(int fd);

// get-next_line_utils.c
size_t	strlen_gnl(const char *s);
char	*strchr_gnl(const char *s, int c);
char	*strjoin_gnl(char *s1, char *s2);
void	cpy_gnl(char *res, char *s1, char *s2);

/*Math*/
int		ft_abs(int a);
int		ft_min(int a, int b);
int		ft_max(int a, int b);

#endif
