/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_flag_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:32:32 by jcosta-b          #+#    #+#             */
/*   Updated: 2024/12/16 11:43:58 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	printf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	flag_minus(t_printf spec)
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
