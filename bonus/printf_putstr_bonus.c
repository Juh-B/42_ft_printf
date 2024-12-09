/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:12:53 by jcosta-b          #+#    #+#             */
/*   Updated: 2024/12/04 13:18:34 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	printf_putstr(char *s)
{
	int	i;

	if (s == NULL)
		return (printf_putstr("(null)"));
	i = 0;
	while (s[i])
		i += printf_putchar(s[i]);
	return (i);
}

size_t	printf_putstr_flag(char flag, unsigned int width, char *s)
{
	int	i;
  size_t len;
  size_t  printed;

	if (s == NULL)
		return (printf_putstr("(null)"));
  printed = 0;
  len = 0;
  while (s[len])
		len++;
  if (flag == ' ' && len < width)
  {
    len = width - len;
    while (len > 0)
    {
			printed += printf_putchar(flag);
      len--;
    }
  }
	i = 0;
	while (s[i])
  {
		printed += printf_putchar(s[i]);
    i++;
  }
	return (printed);
}
