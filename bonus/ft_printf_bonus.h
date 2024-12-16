/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcosta-b <jcosta-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:39:07 by jcosta-b          #+#    #+#             */
/*   Updated: 2024/12/16 11:43:45 by jcosta-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct spec_format
{
	char	flag;
	size_t	width;
	char	prec_flag;
	size_t	prec_len;
	char	spec;
}			t_printf;

int		ft_printf(const char *fmt_str, ...);
size_t	printf_putchar(char c);
size_t	printf_putstr(char *s);
size_t	printf_putnbr(int n);
size_t	printf_putnbr_unsig(unsigned int n);
size_t	printf_puthex(unsigned long n, const char base_specifier);

size_t	flag_minus(t_printf spec);
size_t	flag_str(t_printf spec, char *s);
size_t	flag_nbr(t_printf spec, int n);
size_t	flag_unsnbr(t_printf spec, unsigned int n);
size_t	flag_hex(t_printf spec, unsigned long n);
size_t	flag_ptr(t_printf spec, va_list args);
size_t	put_width(t_printf spec, size_t len_str_w, int n);
size_t	put_w_unbr(t_printf spec, size_t len_str_w);
size_t	put_w_hex(t_printf spec, size_t len_str_w);
void	strlen_nbr(t_printf spec, int n, size_t *len_str_w, size_t *len_str_p);
void	len_unbr(t_printf spec, unsigned int n, size_t *len_w, size_t *len_p);
void	len_hex(t_printf spec, unsigned long n, size_t *len_w, size_t *len_p);

#endif