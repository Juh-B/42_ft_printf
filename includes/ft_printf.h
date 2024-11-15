#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int     ft_printf(const char *fmt_str, ...);
size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putstr_fd(char *s, int fd);
size_t	ft_putnbr_fd(int n, int fd);
size_t	ft_putnbr_unsig_fd(unsigned int n, int fd);
size_t	ft_puthex_fd(unsigned long n, const char base_specifier, int fd);
size_t  ft_putptr(va_list args, char c);

#endif
