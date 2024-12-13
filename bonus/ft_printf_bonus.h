/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:17:25 by jcosta-b          #+#    #+#             */
/*   Updated: 2024/12/12 18:06:16 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	spec_format
{
	char	flag;
	size_t	width;
	char	prec_flag;
	size_t	prec_len;
	char	spec;
}			printf_format;

int		ft_printf(const char *fmt_str, ...);
size_t	printf_putchar(char c);
size_t	printf_putstr(char *s);
size_t	printf_putnbr(int n);
size_t	printf_putnbr_unsig(unsigned int n);
size_t	printf_puthex(unsigned long n, const char base_specifier);

size_t	flag_minus(printf_format spec);
size_t	flag_str(printf_format spec, char *s);
size_t	flag_nbr(printf_format spec, int n);
size_t	flag_unsnbr(printf_format spec, unsigned int n);
void  strlen_nbr(printf_format spec, int n, size_t *len_str_w, size_t *len_str_p);
void	len_unbr(printf_format spec, unsigned int n, size_t *len_w, size_t *len_p);
void	len_hex(printf_format spec, unsigned long n, size_t *len_w, size_t *len_p);
size_t  put_width(printf_format spec, size_t len_str_w, int n);
size_t  put_w_unbr(printf_format spec, size_t len_str_w);
size_t  put_w_hex(printf_format spec, size_t len_str_w);
size_t	flag_hex(printf_format spec, unsigned long n);
size_t	flag_ptr(printf_format spec, va_list args);

#endif
