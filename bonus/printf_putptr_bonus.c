/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:13:40 by jcosta-b          #+#    #+#             */
/*   Updated: 2024/12/04 13:18:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	printf_putptr_flag(va_list args, char c, char flag, unsigned int width)
{
	unsigned long	ptr;
	size_t			printed;

	printed = 0;
	ptr = va_arg(args, unsigned long);
	if (ptr == 0)
		printed += printf_putstr("(nil)");
	else
	{
		printed += printf_putstr("0x");
		printed += printf_puthex_flag(ptr, c, flag, width);
	}
	return (printed);
}
