*This project has been created as part of the 42 curriculum by muballou.*

# Libft

Your very first own library: a static C library (`libft.a`) with re-implementations of standard libc functions, extra string/memory/output helpers, and linked-list utilities.

## Description

**Goal.** Understand how common C functions really work by writing them from scratch, following the 42 Norm, and packaging them into a reusable library for later 42 projects.

**Overview.**

- Strict `-Wall -Wextra -Werror` compilation, using `cc`.
- Library built with `ar` (no `libtool`).
- No global variables; no external functions beyond `malloc`, `free` and `write`.
- Same prototypes and behavior as the libc originals, with an `ft_` prefix.

### Part 1: libc functions

| Group | Functions |
| --- | --- |
| Character tests | `ft_isalpha` `ft_isdigit` `ft_isalnum` `ft_isascii` `ft_isprint` |
| Character conversion | `ft_toupper` `ft_tolower` |
| Strings | `ft_strlen` `ft_strchr` `ft_strrchr` `ft_strncmp` `ft_strnstr` `ft_strlcpy` `ft_strlcat` `ft_atoi` |
| Memory | `ft_memset` `ft_bzero` `ft_memcpy` `ft_memmove` `ft_memchr` `ft_memcmp` |
| Allocation | `ft_calloc` `ft_strdup` |

### Part 2: additional functions

| Function | Description |
| --- | --- |
| `ft_substr` | Allocates a substring of `s` (from `start`, up to `len`). |
| `ft_strjoin` | Allocates the concatenation of two strings. |
| `ft_strtrim` | Allocates a copy of `s1` with characters from `set` trimmed at both ends. |
| `ft_split` | Splits a string on a delimiter into a NULL-terminated array of allocated strings. |
| `ft_itoa` | Converts an `int` (negatives included) to an allocated string. |
| `ft_strmapi` | Builds a new string by applying `f(index, char)` to each character. |
| `ft_striteri` | Applies `f(index, &char)` to each character in place. |
| `ft_putchar_fd` `ft_putstr_fd` `ft_putendl_fd` `ft_putnbr_fd` | Write a char, string, string + newline, or integer to a file descriptor. |

### Part 3: linked lists

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| Function | Description |
| --- | --- |
| `ft_lstnew` | Creates a node holding `content`. |
| `ft_lstadd_front` / `ft_lstadd_back` | Adds a node at the beginning / end. |
| `ft_lstsize` | Counts the nodes. |
| `ft_lstlast` | Returns the last node. |
| `ft_lstdelone` | Frees one node's content (via `del`) and the node itself. |
| `ft_lstclear` | Frees a node and all its successors, then sets the list pointer to `NULL`. |
| `ft_lstiter` | Applies `f` to each node's content. |
| `ft_lstmap` | Builds a new list from `f(content)`, using `del` to clean up on failure. |

## Instructions

```bash
git clone git@vogsphere.1337.ma:vogsphere/intra-uuid-b572fd51-739e-468d-9fc4-06d81d3ebb5c-7738741-muballou libft
cd libft
make            # builds libft.a
```

| Rule | Effect |
| --- | --- |
| `make` / `make all` | Compiles every `ft_*.c` and creates `libft.a`. |
| `make clean` | Removes object files. |
| `make fclean` | Removes object files and `libft.a`. |
| `make re` | `fclean`, then `all`. |

Use it in your own program:

```c
#include "libft.h"
```

```bash
cc -Wall -Wextra -Werror main.c -o my_program
```

## Resources

**References**

- [Linux man pages](https://man7.org/linux/man-pages/): behavior of every re-implemented function (`man 3 strlcpy`, `man 3 memchr`, ...).
- [GNU Make manual](https://www.geeksforgeeks.org/): explainations and examples.
- [C concepts](https://www.learn-c.org/): uses and exercices.

**Use of AI**

AI was used as a tutor, not to write the library code:

- Explaining concepts when I was stuck: why `ctype` functions take an `int` (`EOF`), why `mem*` functions use `unsigned char`, plus generating questions and exercies.
- Suggesting small throwaway test programs for edge cases (`EOF`, signed vs unsigned `char`, `n = 0`).
- helping to create my idea about how the algo and steps supposed to move.

All C source files in this repository were written by me btw.