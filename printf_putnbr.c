/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:12:21 by jcosta-b          #+#    #+#             */
/*   Updated: 2024/12/06 19:15:38 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	printf_putnbr(int n)
{
	long	num;
	size_t	count;

	num = n;
	count = 0;
	if (num < 0)
	{
		num = -num;
		count += printf_putchar(45);
	}
	if (num >= 10)
		count += printf_putnbr(num / 10);
	count += printf_putchar((num % 10) + '0');
	return (count);
}

size_t	printf_putnbr_flag(int n, char flag)
{
	long	num;
	size_t	count;

	num = n;
	count = 0;
	if ((flag == '+' || flag == ' ') && num > 0)
		count += printf_putchar(flag);
	if (num < 0)
	{
		num = -num;
		count += printf_putchar(45);
	}
	if (num >= 10)
		count += printf_putnbr(num / 10);
	count += printf_putchar((num % 10) + '0');
	return (count);
}