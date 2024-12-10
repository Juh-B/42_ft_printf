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

size_t  print_space(size_t len, unsigned int width)
{
  size_t  printed;

  printed = 0;
  len = width - len;
  while (len > 0)
  {
    printed += printf_putchar(' ');
    len--;
  }
  return (printed);
}

size_t	printf_putstr_flag(char flag, unsigned int width, char *s)
{
	size_t	i;
  size_t len;
  size_t  printed;

	if (s == NULL)
		return (printf_putstr(s));
  printed = 0;
  len = 0;
  while (s[len])
		len++;
  if ((flag == ' ' || flag == '%') && len < width)
    printed += print_space(len, width);
  i = 0;
  if (flag == '.' && width < len)
  {
    while (i < width)
    {
      printed += printf_putchar(s[i]);
      i++;
    }
  }
  else
  {
    while (s[i])
    {
      printed += printf_putchar(s[i]);
      i++;
    }
  }
  if (flag == '-' && len < width)
    printed += print_space(len, width);
	return (printed);
}
