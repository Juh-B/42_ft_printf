/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_flag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:18:30 by jcosta-b          #+#    #+#             */
/*   Updated: 2024/12/12 16:07:03 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	printf_putstr(char *s)
{
	int	i;

	if (s == NULL)
		return (printf_putstr("(null)"));
	i = 0;
	while (s[i])
		i += printf_putchar(s[i]);
	return (i);
}

static size_t	verif_space(printf_format spec, size_t len)
{
	size_t	printed;

	printed = 0;
	if(spec.prec_flag == '.' && spec.width > spec.prec_len)
		len = spec.width - spec.prec_len;
	else
		len = spec.width - len;
	while (len > 0)
	{
		printed += printf_putchar(' ');
		len--;
	}
	return (printed);
}

static size_t	putstr_prec(printf_format spec, size_t len, char *s)
{
	size_t	printed;
	size_t	i;

	i = 0;
	printed = 0;
	if (spec.prec_flag == '.' && spec.prec_len < len)
	{
		while (i < spec.prec_len)
			printed += printf_putchar(s[i++]);
	}
	else
	{
		while (s[i])
			printed += printf_putchar(s[i++]);
	}
	return (printed);
}

size_t	flag_str(printf_format spec, char *s)
{
	size_t	len;
	size_t	printed;

	if (s == NULL)
		return (printf_putstr(s));
	printed = 0;
	len = 0;
	while (s[len])
		len++;

	if ((spec.flag == ' ' || spec.flag == '\0') && len < spec.width)
		printed += verif_space(spec, len);
	printed += putstr_prec(spec, len, s);
	if (spec.flag == '-' && len < spec.width)
		printed += verif_space(spec, len);
	return (printed);
}
