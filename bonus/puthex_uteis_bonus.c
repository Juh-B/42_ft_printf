/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex_uteis_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:34:34 by jcosta-b          #+#    #+#             */
/*   Updated: 2024/12/16 11:36:32 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	howmuch_dig_hex(unsigned long n)
{
	unsigned long	num;
	size_t			dig;

	num = n;
	dig = 0;
	if (n == 0)
		dig++;
	while (num > 0)
	{
		num /= 16;
		dig++;
	}
	return (dig);
}

void	len_hex(t_printf spec, unsigned long n, size_t *len_w, size_t *len_p)
{
	size_t	len_num;

	len_num = 0;
	len_num = howmuch_dig_hex(n);
	if (spec.prec_flag == '.' && spec.prec_len > len_num)
		*len_p = spec.prec_len - len_num;
	if (spec.flag == '#' || spec.spec == 'p')
		len_num += 2;
	if (spec.width > len_num)
	{
		*len_w = spec.width - len_num;
		if (spec.prec_flag == '.')
			*len_w = *len_w - *len_p;
	}
}

size_t	put_w_hex(t_printf spec, size_t len_str_w)
{
	size_t	count;

	count = 0;
	while (len_str_w > 0 && spec.flag != '0')
	{
		count += printf_putchar(' ');
		len_str_w--;
	}
	while (len_str_w > 0 && spec.flag == '0')
	{
		count += printf_putchar('0');
		len_str_w--;
	}
	return (count);
}
