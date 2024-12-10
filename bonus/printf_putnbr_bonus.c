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
	long  num;
	size_t	count;

	num = n;
	count = 0;
	if (num < 0)
		num = -num;
	if (num >= 10)
		count += printf_putnbr(num / 10);
	count += printf_putchar((num % 10) + '0');
	return (count);
}

size_t  putflags(char flag, unsigned int width, int n, size_t dig)
{
  size_t	count;

  if (flag == '-' || flag == '%')
    flag = ' ';
  else if (flag == '.')
    flag = '0';
	count = 0;
  if (dig < width)
  {
    if (n == 0)
      dig = width - 1;
    else
      dig = width - dig;
    while (dig > 0)
    {
			count += printf_putchar(flag);
      dig--;
    }
  }
  return (count);
}

size_t	printf_putnbr_flag(int n, char flag, unsigned int width)
{
	size_t	count;
  size_t  dig;
  long  num;

	count = 0;
  dig = 0;
  num = n;
	// if ((flag == '+' || flag == ' ' || flag == '0') && n >= 0)
	if (n < 0)
  {
    if (flag != '.')
      dig++;
    num = -num;
    count += printf_putchar(45);
  }
  while (num > 0)
  {
    num /= 10;
    dig++;
  }
  if (flag == '+' && n >= 0)
		count += printf_putchar(flag);
  else if (flag == '.' && width == 0 && n == 0)
    return (0);
  // else if ((flag == '0' || flag == ' ') && width == 0 && n >= 0)
  //   count += printf_putchar(flag);
  else if (flag == '0' || flag == ' ' || flag == '%' || flag == '.')
    count += putflags(flag, width, n, dig);
  count += printf_putnbr(n);
  if (flag == '-')
    count += putflags(flag, width, n, dig);
	return (count);
}
