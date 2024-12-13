#include "ft_printf_bonus.h"

static size_t	howmuch_dig(int n)
{
	long	num;
	size_t	dig;

	num = n;
	dig = 0;
	if (n <= 0)
	{
		dig++;
		num = -num;
	}
	while (num > 0)
	{
		num /= 10;
		dig++;
	}
	return (dig);
}

void	strlen_nbr(printf_format spec, int n, size_t *len_str_w, size_t *len_str_p)
{
	size_t	len_num;

	len_num = 0;
	len_num = howmuch_dig(n);
	if (n < 0)
		len_num--;
	if (spec.prec_flag == '.' && spec.prec_len > len_num)
		*len_str_p = spec.prec_len - len_num;
	if (spec.flag == '+' || n < 0)
		len_num++;
	if (spec.width > len_num)
	{
		*len_str_w = spec.width - len_num;
		if (spec.prec_flag == '.')
			*len_str_w = *len_str_w - *len_str_p;
	}
}

size_t  put_width(printf_format spec, size_t len_str_w, int n)
{
  size_t count;

  count = 0;
  while (len_str_w > 0 && spec.flag != '0')
	{
    count += printf_putchar(' ');
		len_str_w--;
	}
	if (spec.flag == '+' && n >= 0)
		count += printf_putchar('+');
	else if (spec.flag != '-' && n < 0)
		count += printf_putchar('-');
  while (len_str_w > 0 && spec.flag == '0')
	{
    count += printf_putchar('0');
		len_str_w--;
	}
  return (count);
}
