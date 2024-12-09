/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:10:18 by jcosta-b          #+#    #+#             */
/*   Updated: 2024/12/04 13:24:29 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *fmt_str, ...);
size_t	printf_putchar(char c);
size_t	printf_putstr(char *s);
size_t	printf_putnbr(int n);
size_t	printf_putnbr_unsig(unsigned int n);
size_t	printf_puthex(unsigned long n, const char base_specifier);
size_t	printf_putptr(va_list args, char c);

size_t  putflags(char flag, unsigned int width, int n, size_t dig);
size_t	printf_putnbr_flag(int n, char flag, unsigned int width);
size_t	printf_putnbr_unsig_flag(unsigned int n, char flag, unsigned int width);
size_t	printf_puthex_flag(unsigned long n, const char base_specifier, char flag, unsigned int width);
size_t	printf_putstr_flag(char flag, unsigned int width, char *s);


#endif
