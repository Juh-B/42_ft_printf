/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex_flag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:34:17 by jcosta-b          #+#    #+#             */
/*   Updated: 2024/12/16 11:44:10 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	printf_putnbr_base(t_printf spec, unsigned long n)
{
	size_t	count;
	char	*base;

	if (spec.spec == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += printf_putnbr_base(spec, n / 16);
	count += printf_putchar(base[n % 16]);
	return (count);
}

static size_t	putflags_hex(t_printf spec, unsigned long n)
{
	size_t	count;
	size_t	len_str_w;
	size_t	len_str_p;

	len_str_p = 0;
	len_str_w = 0;
	count = 0;
	len_hex(spec, n, &len_str_w, &len_str_p);
	count += put_w_hex(spec, len_str_w);
	if (spec.flag == '#' && n != 0)
	{
		if (spec.spec == 'X')
			count += printf_putstr("0X");
		else
			count += printf_putstr("0x");
	}
	while (len_str_p > 0)
	{
		count += printf_putchar('0');
		len_str_p--;
	}
	count += printf_putnbr_base(spec, n);
	return (count);
}

static size_t	putflag_hex_minus(t_printf spec, unsigned long n)
{
	size_t	count;
	size_t	len_str_w;
	size_t	len_str_p;

	len_str_p = 0;
	len_str_w = 0;
	count = 0;
	len_hex(spec, n, &len_str_w, &len_str_p);
	if (spec.flag == '#' && n != 0)
	{
		if (spec.spec == 'X')
			count += printf_putstr("0X");
		else if (spec.spec == 'x')
			count += printf_putstr("0x");
	}
	while (len_str_p > 0)
	{
		count += printf_putchar('0');
		len_str_p--;
	}
	if (!(spec.prec_flag == '.' && n == 0))
		count += printf_putnbr_base(spec, n);
	count += put_w_hex(spec, len_str_w);
	return (count);
}

size_t	flag_hex(t_printf spec, unsigned long n)
{
	size_t	count;

	count = 0;
	if ((spec.flag == '0' || spec.flag == ' ') && spec.width == 0)
		count += printf_putchar(spec.flag);
	else if (spec.flag != '-')
		count += putflags_hex(spec, n);
	else
		count += putflag_hex_minus(spec, n);
	return (count);
}
