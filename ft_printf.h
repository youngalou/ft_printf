/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:44:15 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/11 14:48:53 by lyoung           ###   ########.fr       */
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
# define F_CONV (*spec == 's' || *spec == 'S' || *spec == 'd' || *spec == 'D' || *spec == 'i' || *spec == 'c' || *spec == 'C' || *spec == 'u' || *spec == 'U' || *spec == 'o' || *spec == 'O' || *spec == 'x' || *spec == 'X' || *spec == 'p' || *spec == '%')
# define F_CAPS (*spec == 'S' || *spec == 'D' || *spec == 'C' || *spec == 'U' || *spec == 'O')
# define F_MOD (*spec == 'h' || *spec == 'l' || *spec == 'z' || *spec == 'j')

/*
** hh  = 1	:	unsigned char
** h = 2	:	unsigned short
** l  = 3	:	long
** ll = 4	:	long long
** z  = 5	:	size_t
** j  = 6	:	intmax_t
*/

typedef enum
{
	t_uchar = 1,
	t_ushort,
	t_long,
	t_longlong,
	t_sizet,
	t_intmaxt
}	length;

typedef struct	s_args
{
	length		length;
}				t_args;

typedef struct	s_res
{
	char		*out;
	size_t		len;
	size_t		cap;
}				t_res;

int				ft_printf(const char *format, ...);
char			*handle_args(const char *fmt, char *place, t_res *res,
							va_list ap);

void			handle_conv(char *spec, t_res *res, va_list ap, t_args *mod);
void    		percent_conv(t_res *res, va_list ap);
void			string_conv(t_res *res, va_list ap, t_args *mod);
void			decimal_conv(t_res *res, va_list ap, t_args *mod);
void			char_conv(t_res *res, va_list ap, t_args *mod);
void			unsigned_int_conv(t_res *res, va_list ap, t_args *mod);
void			unsigned_oct_conv(t_res *res, va_list ap, t_args *mod);
void			unsigned_hex_conv(t_res *res, va_list ap, char conv, t_args *mod);
void			pointer_conv(t_res *res, va_list ap);

char			*search_mods(char *place, t_args *mod);
intmax_t		uox_len(va_list ap, t_args *mod);
intmax_t		di_len(va_list ap, t_args *mod);

t_res			*init_res(size_t cap);
int				resize_res(t_res *res, size_t size);
void			check_res(t_res *res, size_t size);

#endif
