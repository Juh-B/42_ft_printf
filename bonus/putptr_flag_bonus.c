/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putptr_flag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:34:51 by jcosta-b          #+#    #+#             */
/*   Updated: 2024/12/16 11:37:13 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	flag_ptr(t_printf spec, va_list args)
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
		printed += flag_hex(spec, ptr);
	}
	return (printed);
}
