/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:11:28 by jcosta-b          #+#    #+#             */
/*   Updated: 2024/12/06 19:00:01 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static size_t	printf_specifiers(char flag, unsigned int width, va_list args, char c)
{
	size_t	printed;

	printed = 0;
	if (c == 'c')
  {
		printed += printf_putchar(va_arg(args, int));
    printed += flag_menus(flag, width);
  }
	else if (c == 's')
		printed += printf_putstr_flag(flag, width, va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		printed += printf_putnbr_flag(va_arg(args, int), flag, width);
	else if (c == 'u')
		printed += printf_putnbr_unsig_flag(va_arg(args, unsigned int), flag, width);
	else if (c == 'x' || c == 'X')
		printed += printf_puthex_flag(va_arg(args, unsigned int), c, flag, width);
	else if (c == 'p')
		printed += printf_putptr_flag(args, c, flag, width);
	else if (c == '%')
		printed += printf_putchar('%');
	return (printed);
}

int	ft_printf(const char *fmt_str, ...)
{
	va_list	args;
	size_t		i;
	size_t	printed;
  unsigned int  width;
  size_t  w_len;

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
      width = 0;
      w_len = 1;
			if (fmt_str[i] == '+' || fmt_str[i] == ' ' || fmt_str[i] == '#'||
      fmt_str[i] == '0' || fmt_str[i] == '-' || fmt_str[i] == '.')
				i++;
      while (ft_isdigit(fmt_str[i]))
      {
        width = (width * 10) + (fmt_str[i] - '0');
		    i++;
        w_len++;
      }
			printed += printf_specifiers(fmt_str[i - w_len], width, args, fmt_str[i]);
			i++;
		}
		else
		{
			printed += printf_putchar(fmt_str[i]);
			i++;
		}
	}
	va_end(args);
	return (printed);
}
