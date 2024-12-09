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

size_t	printf_puthex_flag(unsigned long n, const char base_specifier, char flag)
{
  size_t	count;

	count = 0;
  if (flag == '+' || flag == ' ' || flag == '0')
		count += printf_putchar(flag);
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
