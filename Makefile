# Project name
NAME = libftprintf.a

# .c files
SRC = \
	srcs/ft_printf.c srcs/printf_putchar.c srcs/printf_puthex.c srcs/printf_putnbr.c\
	srcs/printf_putnbr_unsig.c srcs/printf_putptr.c srcs/printf_putstr.c

# .c files from bonus
SRC_BONUS = \
	bonus/ft_printf_bonus.c bonus/putchar_flag_bonus.c bonus/putstr_flag_bonus.c\
	bonus/putnbr_flag_bonus.c bonus/putnbr_uteis_bonus.c\
	bonus/putnbr_uns_flag_bonus.c bonus/putnbr_unsig_uteis_bonus.c\
	bonus/puthex_flag_bonus.c bonus/puthex_uteis_bonus.c\
	bonus/putptr_flag_bonus.c

# .h files
INCLUDES = ft_printf.h ft_printf_bonus.h

# Object files
OBJ = $(SRC:.c=.o)

# Object files from bonus
OBJ_BONUS = $(SRC_BONUS:.c=.o)

ADD_BONUS = .bonus

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Compilation
all: $(NAME)

# Comp lib
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Bonus
bonus: $(ADD_BONUS)

$(ADD_BONUS): $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)
	touch $(ADD_BONUS)

# Compile all files
%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean obj files
clean:
	rm -f $(OBJ) $(OBJ_BONUS)

# Clean obj files and lib
fclean: clean
	rm -f $(NAME) $(ADD_BONUS)

# Clean all
re: fclean all

# Ghost files
.PHONY: all bonus clean fclean re
