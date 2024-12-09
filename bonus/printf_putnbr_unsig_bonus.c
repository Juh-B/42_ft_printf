/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putnbr_unsig.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:12:39 by jcosta-b          #+#    #+#             */
/*   Updated: 2024/12/04 13:19:56 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	printf_putnbr_unsig(unsigned int n)
{
	size_t	count;

	count = 0;
	if (n >= 10)
		count += printf_putnbr_unsig(n / 10);
	count += printf_putchar((n % 10) + '0');
	return (count);
}

size_t	printf_putnbr_unsig_flag(unsigned int n, char flag)
{
	size_t	count;

	count = 0;
	if (flag == '+' || flag == ' ' || flag == '0')
		count += printf_putchar(flag);
	count += printf_putnbr_unsig(n);
	return (count);
}
