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

// int	ft_isdigit(char c)
// {
// 	if (c >= '0' && c <= '9')
// 		return (1);
// 	return (0);
// }

// static size_t	printf_width(char c)
// {
// 	size_t	printed;

// 	printed = 0;
// 	if (ft_isdigit(c))
// 		printed += printf_putchar(v);
// 	return (printed);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	int				i;
// 	unsigned char	ch;

// 	ch = (unsigned char)c;
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == ch)
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	if (ch == '\0')
// 		return ((char *)&s[i]);
// 	return (NULL);
// }

// static size_t	printf_flags(char c, char ch)
// {
// 	size_t	printed;
// 	char	*interger;

// 	interger = "diuxX";
// 	printed = 0;
// 	if (c == '+' && ft_strchr(interger, ch))
// 		printed += printf_putchar('+');
// 	else if (c == ' ')
// 		printed += printf_putstr(va_arg(args, char *));
// 	else if (c == '#')
// 		printed += printf_putnbr(va_arg(args, int));
// 	return (printed);
// }

static size_t	printf_specifiers(va_list args, char c, char flag)
{
	size_t	printed;

	printed = 0;
	if (c == 'c' || c == 's')
	{
		if (flag == ' ')
			printed += printf_putchar(flag);
		if (c == 'c')
			printed += printf_putchar(va_arg(args, int));
		else
			printed += printf_putstr(va_arg(args, char *));
	}
	else if (c == 'd' || c == 'i')
		printed += printf_putnbr_flag(va_arg(args, int), flag);
	else if (c == 'u')
		printed += printf_putnbr_unsig(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		printed += printf_puthex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		printed += printf_putptr(args, c);
	else if (c == '%')
		printed += printf_putchar('%');
	return (printed);
}

int	ft_printf(const char *fmt_str, ...)
{
	va_list	args;
	size_t		i;
	size_t	printed;
	// size_t	extra;

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
			// if (fmt_str[i] == '+' || fmt_str[i] == ' ' || fmt_str[i] == '#')
			// {
			// 	extra = 0;
			// 	extra += printf_flags(fmt_str[i], fmt_str[i + 1]);
			// 	i += extra;
			// 	printed += extra;
			// }
			if (fmt_str[i] == '+' || fmt_str[i] == ' ' || fmt_str[i] == '#')
			{
				i++;
				printed += printf_specifiers(args, fmt_str[i], fmt_str[i - 1]);
			}
			printed += printf_specifiers(args, fmt_str[i], fmt_str[i - 1]);
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