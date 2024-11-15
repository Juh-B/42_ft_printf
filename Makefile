# Project name
NAME = libftprintf.a

# .c files
SRC = \
		srcs/ft_printf.c srcs/ft_putchar_fd.c srcs/ft_puthex_fd.c srcs/ft_putnbr_fd.c\
		srcs/ft_putnbr_unsig_fd.c srcs/ft_putptr.c srcs/ft_putstr_fd.c

# .h files
INCLUDES = -Iincludes
# DESP = ft_printf.h

# Object files
OBJ = $(SRC:.c=.o)

# Compilator and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Compilation
all: $(NAME)

# Comp lib
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Comp all files
%.o: %.c $(DESP)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean obj files
clean:
	rm -f $(OBJ)

# Clean obj files and lib
fclean: clean
	rm -f $(NAME)

# Clean all
re: fclean all

# Ghost files
.PHONY: all clean fclean re
