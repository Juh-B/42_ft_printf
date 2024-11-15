#include "../includes/ft_printf.h"

static size_t	ft_putnbr_base_fd(unsigned long n, const char *base, int fd)
{
  size_t count;

  count = 0;
	if (n >= 16)
		count += ft_putnbr_base_fd(n / 16, base, fd);
	count += ft_putchar_fd(base[n % 16], fd);
  return (count);
}

size_t	ft_puthex_fd(unsigned long n, const char base_specifier, int fd)
{
	if (base_specifier == 'X')
		return (ft_putnbr_base_fd(n, "0123456789ABCDEF", fd));
	else
		return (ft_putnbr_base_fd(n, "0123456789abcdef", fd));
}
