/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_flag_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:17:46 by jcosta-b          #+#    #+#             */
/*   Updated: 2024/12/12 15:05:59 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	printf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	flag_minus(printf_format spec)
{
	size_t	count;

		count = 0;
	if (spec.flag == '-')
	{
		while ((spec.width - 1) > 0)
		{
			count++;
			spec.width--;
			printf_putchar(' ');
		}
	}
	return (count);
}
