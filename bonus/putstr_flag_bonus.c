/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_flag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:32:45 by jcosta-b          #+#    #+#             */
/*   Updated: 2024/12/16 12:02:00 by jcosta-b         ###   ########.fr       */
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

static size_t	put_space(t_printf spec, size_t len, char *s)
{
	size_t	printed;

	printed = 0;
	if (spec.prec_flag == '.' && s == NULL)
		len = spec.width;
	else if (spec.prec_flag == '.' && spec.prec_len <= len)
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

static size_t	putstr_prec(t_printf spec, size_t len, char *s)
{
	size_t	printed;
	size_t	i;

	i = 0;
	printed = 0;
	if (s == NULL && spec.prec_flag != '.')
		return (printf_putstr(s));
	if (spec.prec_flag == '.' && spec.prec_len < len)
	{
		while (i < spec.prec_len)
			printed += printf_putchar(s[i++]);
	}
	else if (s != NULL)
	{
		while (s[i])
			printed += printf_putchar(s[i++]);
	}
	return (printed);
}

static size_t	verif_space(t_printf spec, char *s, size_t len)
{
	size_t	printed;

	printed = 0;
	if (s == NULL && spec.width > 6)
		printed += put_space(spec, len, s);
	else if ((len < spec.width || (len - spec.prec_len) < spec.width))
		printed += put_space(spec, len, s);
	return (printed);
}

size_t	flag_str(t_printf spec, char *s)
{
	size_t	len;
	size_t	printed;

	printed = 0;
	len = 0;
	if (s == NULL)
	{	
		if (spec.prec_flag != '.')
			len = 6;
	}
	else
	{
		while (s[len])
			len++;
	}
	if (spec.flag == ' ' || spec.flag == '\0')
		printed += verif_space(spec, s, len);
	printed += putstr_prec(spec, len, s);
	if (spec.flag == '-')
		printed += verif_space(spec, s, len);
	return (printed);
}
