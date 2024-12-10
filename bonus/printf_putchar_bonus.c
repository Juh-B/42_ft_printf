/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:11:47 by jcosta-b          #+#    #+#             */
/*   Updated: 2024/12/04 13:17:53 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	printf_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	flag_menus(char flag, unsigned int  width)
{
  size_t  count;

  count = 0;
  if (flag == '-')
  {
    while ((width - 1) > 0)
    {
      count++;
      width--;
      printf_putchar(' ');
    }
  }
	return (count);
}
