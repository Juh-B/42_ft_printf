#include "../includes/ft_printf.h"

size_t	ft_putnbr_unsig_fd(unsigned int n, int fd)
{
  size_t count;

  count = 0;
	if (n >= 10)
	  count += ft_putnbr_unsig_fd(n / 10, fd);
	count += ft_putchar_fd((n % 10) + '0', fd);
  return (count);
}
