/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_flag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:18:09 by jcosta-b          #+#    #+#             */
/*   Updated: 2024/12/12 18:22:23 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	printf_putnbr(int n)
{
	long	num;
	size_t	count;

	num = n;
	count = 0;
	if (num < 0)
		num = -num;
	if (num >= 10)
		count += printf_putnbr(num / 10);
	count += printf_putchar((num % 10) + '0');
	return (count);
}

static size_t	putflags(printf_format spec, int n)
{
	size_t	count;
	size_t	len_str_w;
	size_t	len_str_p;

	len_str_p = 0;
	len_str_w = 0;
	count = 0;
	strlen_nbr(spec, n, &len_str_w, &len_str_p);
  count += put_width(spec, len_str_w, n);
	while (len_str_p > 0)
	{
		count += printf_putchar('0');
		len_str_p--;
	}
	count += printf_putnbr(n);
	return (count);
}

static size_t	putflag_minus(printf_format spec, int n)
{
	size_t	count;
	size_t	len_str_w;
	size_t	len_str_p;

	len_str_p = 0;
	len_str_w = 0;
	count = 0;
	strlen_nbr(spec, n, &len_str_w, &len_str_p);
	if (n < 0)
		count += printf_putchar('-');
	while (len_str_p > 0)
	{
		count += printf_putchar('0');
		len_str_p--;
	}
  if (!(spec.prec_flag == '.' && n == 0))
		count += printf_putnbr(n);
  count += put_width(spec, len_str_w, n);
	return (count);
}

size_t	flag_nbr(printf_format spec, int n)
{
	size_t	count;

	count = 0;
	if ((spec.flag == '0' || spec.flag == ' ') && spec.width == 0 && n >= 0)
  {
		count += printf_putchar(spec.flag);
    count += printf_putnbr(n);
  }
	else if (spec.flag != '-')
		count += putflags(spec, n);
	else
		count += putflag_minus(spec, n);
	return (count);
}
