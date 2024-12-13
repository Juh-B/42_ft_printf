/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunsnbr_flag_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:18:40 by jcosta-b          #+#    #+#             */
/*   Updated: 2024/12/10 17:18:41 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	printf_putnbr_unsig(unsigned int n)
{
	size_t	count;

	count = 0;
	if (n >= 10)
		count += printf_putnbr_unsig(n / 10);
	count += printf_putchar((n % 10) + '0');
	return (count);
}

static size_t	putflags_unsig(printf_format spec, unsigned int n)
{
	size_t	count;
	size_t	len_str_w;
	size_t	len_str_p;

	len_str_p = 0;
	len_str_w = 0;
	count = 0;
	len_unbr(spec, n, &len_str_w, &len_str_p);
  count += put_w_unbr(spec, len_str_w);
	while (len_str_p > 0)
	{
		count += printf_putchar('0');
		len_str_p--;
	}
	count += printf_putnbr_unsig(n);
	return (count);
}

static size_t	putflag_unsig_minus(printf_format spec, unsigned int n)
{
	size_t	count;
	size_t	len_str_w;
	size_t	len_str_p;

	len_str_p = 0;
	len_str_w = 0;
	count = 0;
	len_unbr(spec, n, &len_str_w, &len_str_p);
	while (len_str_p > 0)
	{
		count += printf_putchar('0');
		len_str_p--;
	}
  if (!(spec.prec_flag == '.' && n == 0))
		count += printf_putnbr_unsig(n);
  count += put_w_unbr(spec, len_str_w);
	return (count);
}

size_t	flag_unsnbr(printf_format spec, unsigned int n)
{
  size_t	count;

	count = 0;
	if ((spec.flag == '0' || spec.flag == ' ') && spec.width == 0)
  {
		count += printf_putchar(spec.flag);
    count += printf_putnbr_unsig(n);
  }
	else if (spec.flag != '-')
		count += putflags_unsig(spec, n);
	else
		count += putflag_unsig_minus(spec, n);
	return (count);
}
