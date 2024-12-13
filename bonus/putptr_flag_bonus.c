/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putptr_flag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:18:19 by jcosta-b          #+#    #+#             */
/*   Updated: 2024/12/11 18:09:57 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	flag_ptr(printf_format spec, va_list args)
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
