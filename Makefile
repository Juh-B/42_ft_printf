# Project name
NAME = libftprintf.a

# .c files
SRC = ft_printf.c

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
