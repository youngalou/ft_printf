/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:44:15 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/08 12:31:16 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "./libft/libft.h"
# include <stdio.h>

typedef struct	s_args
{
	int			length;
}				t_args;

typedef struct	s_res
{
	char		*out;
	size_t		len;
	size_t		cap;
}				t_res;

int		ft_printf(const char *format, ...);
void    handle_args(const char *fmt, va_list ap, char *spec, t_res *res);

void    string_conv(t_res *res, va_list ap);
void	decimal_conv(t_res *res, va_list ap);
void    char_conv(t_res *res, va_list ap);
void	unsigned_int_conv(t_res *res, va_list ap);
void	unsigned_hex_conv(t_res *res, va_list ap);
void	unsigned_oct_conv(t_res *res, va_list ap);

void	search_mods(char *place);

t_res	*init_res(size_t cap);
int		resize_res(t_res *res, size_t size);
void	check_res(t_res *res, size_t size);

#endif
