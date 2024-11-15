#include "../includes/ft_printf.h"

size_t	ft_putnbr_fd(int n, int fd)
{
	long  num;
  size_t  count;

	num = n;
  count = 0;
	if (num < 0)
	{
		num = -num;
		count += ft_putchar_fd(45, fd);
	}
	if (num >= 10)
		count += ft_putnbr_fd(num / 10, fd);
	count += ft_putchar_fd((num % 10) + '0', fd);
  return (count);
}
