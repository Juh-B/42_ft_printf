/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:17:12 by jcosta-b          #+#    #+#             */
/*   Updated: 2024/12/12 16:10:04 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	printf_spec(printf_format spec, va_list args)
{
	size_t	printed;

	printed = 0;
	if (spec.spec == 'c')
	{
		printed += printf_putchar(va_arg(args, int));
		printed += flag_minus(spec);
	}
	else if (spec.spec == 's')
		printed += flag_str(spec, va_arg(args, char *));
	else if (spec.spec == 'd' || spec.spec == 'i')
		printed += flag_nbr(spec, va_arg(args, int));
	else if (spec.spec == 'u')
		printed += flag_unsnbr(spec, va_arg(args, unsigned int));
	else if (spec.spec == 'x' || spec.spec == 'X')
		printed += flag_hex(spec, va_arg(args, unsigned int));
	else if (spec.spec == 'p')
		printed += flag_ptr(spec, args);
	else if (spec.spec == '%')
		printed += printf_putchar('%');
	return (printed);
}

void	init_spec_format(printf_format *spec)
{
	spec->flag = '\0';
	spec->width = 0;
	spec->prec_flag = '\0';
	spec->prec_len = 0;
	spec->spec = '\0';
}

static int	verfic_flag(va_list args, const char *str, size_t *printed)
{
	int	i;
	printf_format	spec;

	init_spec_format(&spec);
	i = 0;
	if (str[i] == '+' || str[i] == ' ' || str[i] == '#' ||
		str[i] == '0' || str[i] == '-')
			spec.flag = str[i++];
	while (str[i] >= '0' && str[i] <= '9')
	{
		spec.width = (spec.width * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		spec.prec_flag = str[i++];
		while (str[i] >= '0' && str[i] <= '9')
		{
			spec.prec_len = (spec.prec_len * 10) + (str[i] - '0');
			i++;
		}
	}
	spec.spec = str[i];
	*printed += printf_spec(spec, args);
	return (i);
}

int	ft_printf(const char *fmt_str, ...)
{
	va_list			args;
	size_t			i;
	size_t			printed;

	if (!fmt_str)
		return (-1);
	va_start(args, fmt_str);
	i = 0;
	printed = 0;
	while (fmt_str[i] != '\0')
	{
		if (fmt_str[i] == '%' && fmt_str[i + 1] != '\0')
		{
			i++;
			i += verfic_flag(args, fmt_str + i, &printed);
			i++;
		}
		else
			printed += printf_putchar(fmt_str[i++]);
	}
	va_end(args);
	return (printed);
}
