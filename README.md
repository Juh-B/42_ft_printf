<h1 align="center">
  ft_printf
</h1>

<p align="center">
	<b><i>42 Project - Reimplementation of printf</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/Juh-B/42_ft_printf?color=lightblue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/Juh-B/42_ft_printf?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/Juh-B/42_ft_printf?color=green" />
</p>

This project is part of the 42 School curriculum and its goal was to **reimplement the standard C `printf` function**.  

The `printf` function in C is used to format and print data to the standard output.  
It allows developers to display text, numbers, characters, and memory addresses using **format specifiers** (such as `%s`, `%d`, `%x`, etc.), while also supporting features like width, precision, and flags for fine control over the output.  

Through this project, I gained hands-on experience with **variadic functions**, format parsing, and robust string and number formatting.  
The result is a fully functional `ft_printf`, mimicking the behavior of the original `printf` with strong focus on **code structure, extensibility, and reliability**.


## Tech Stack

- **Language:** C
- **Build Tool:** Makefile (`-Wall -Wextra -Werror` flags)
- **Norm:** 42 coding standard (Norminette)
- **Version Control:** Git
- **Output:** `libftprintf.a` (static library)
- **Allowed Functions:** `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`  


## Installation

Clone the repository and compile the library:

```bash
git clone https://github.com/Juh-B/42_ft_printf.git
cd 42_ft_printf
make
```

This will generate the static library file:
`libftprintf.a`

**Other available rules:**

```bash
make clean     # Remove object files
make fclean    # Remove object files and libftprintf.a
make re        # Recompile everything
make bonus     # Compile with bonus features
```


## Usage

To use `libftprintf.a` in another project:

Include the header in your source file:

```c
#include "ft_printf.h"
```

Compile your project linking with `libftprintf.a`:

```bash
cc main.c -L. -lftprintf -o my_program
```

_Example:_

```c
ft_printf("Hello %s, the number is %d and hex: %x\n", "world", 42, 42);
```

_Expected output:_

```
Hello world, the number is 42 and hex: 2a
```


## Implemented Conversions

| Specifier | Description |
|-----------|-------------|
| %c | Print a single character |
| %s | Print a string |
| %p | Print a pointer address in hexadecimal |
| %d | Print a decimal (base 10) number |
| %i | Print an integer (base 10) |
| %u | Print an unsigned decimal (base 10) |
| %x | Print a number in lowercase hexadecimal |
| %X | Print a number in uppercase hexadecimal |
| %% | Print a literal % sign |


## Bonus Features

| Flag | Description |
|------|-------------|
| `-` | Left-align the output within the given field width |
| `0` | Pad numeric output with leading zeros |
| `.` | Precision specifier (for strings and numbers) |
| *width* | Minimum field width |
| `#` | Alternate form (e.g., `0x` prefix for hex) |
| `+` | Forces sign (`+` or `-`) to be used |
| (space) | A leading space is added for positive numbers |


_Example (Bonus):_

```c
ft_printf("Number with width: |%5d|\n", 42);
ft_printf("Number with zero-padding: |%05d|\n", 42);
ft_printf("Number with plus flag: |%+d|\n", 42);
ft_printf("Hex with #: |%#x|\n", 42);
```

_Expected output:_

```
Number with width: |   42|
Number with zero-padding: |00042|
Number with plus flag: |+42|
Hex with #: |0x2a|
```

## Learning Outcomes

- Through ft_printf, I improved my skills in:
- Handling variadic functions (stdarg.h)
- Designing modular and extensible code
- Reproducing the behavior of a core C standard library function
- Implementing string and number formatting logic
- Writing memory-safe and efficient C programs
- Applying debugging strategies and custom test cases
