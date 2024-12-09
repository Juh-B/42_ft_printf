#include "../includes/ft_printf.h"

static size_t	printf_putnbr_base(long long n, const char *base)
{
	size_t	count;

	count = 0;
	if (n >= 16)
		count += printf_putnbr_base(n / 16, base);
	count += printf_putchar(base[n % 16]);
	return (count);
}

size_t	printf_puthex_flag(unsigned long n, const char base_specifier, char flag, unsigned int width)
{
  size_t	count;
  size_t  dig;
  unsigned long num;

	count = 0;
  dig = 0;
  num = n;
  while (num > 0)
  {
    num /= 16;
    dig++;
  }
  if (flag == '+')
		count += printf_putchar(flag);
  else if (flag == '0' || flag == ' ' || flag == '-')
    count += putflags(flag, width, n, dig);
  else if (flag == '#' && n != 0)
  {
    if (base_specifier == 'X')
      count += printf_putstr("0X");
    else
      count += printf_putstr("0x");
  }
	if (base_specifier == 'X')
		count += printf_putnbr_base(n, "0123456789ABCDEF");
	else
		count += printf_putnbr_base(n, "0123456789abcdef");
  return (count);
}
