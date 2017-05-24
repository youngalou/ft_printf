/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:44:15 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/23 14:23:03 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "./libft/libft.h"
# include <stdio.h>

# define F_CONV (*spec == 's' || *spec == 'S' || *spec == 'd' || *spec == 'D' || *spec == 'i' || *spec == 'c' || *spec == 'C' || *spec == 'u' || *spec == 'U' || *spec == 'o' || *spec == 'O' || *spec == 'x' || *spec == 'X' || *spec == 'p' || *spec == '%')

# define F_UOX (*spec == 'u' || *spec == 'U' || *spec == 'o' || *spec == 'O' || *spec == 'x' || *spec == 'X')

# define F_CAPS (*spec == 'S' || *spec == 'D' || *spec == 'C' || *spec == 'U' || *spec == 'O')

# define F_MOD (*spec == 'h' || *spec == 'l' || *spec == 'L' || *spec == 'z' || *spec == 'j' || *spec == '.' || *spec == '*' || *spec == '-' || *spec == '+' || *spec == '0' || *spec == ' ' || *spec == '#' || (*spec >= '1' && *spec <= '9'))

# define F_LEN (*spec == 'h' || *spec == 'l' || *spec == 'L' || *spec == 'z' || *spec == 'j')

# define F_FLAGS (*spec == '.' || *spec == '*' || *spec == '-' || *spec == '+' || *spec == '0' || *spec == ' ' || *spec == '#' || (*spec >= '1' && *spec <= '9'))

/*
** hh = 1	:	unsigned char
** h  = 2	:	unsigned short
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
	size_t		width;
	int			prec;
	int			align;
	char		pad;
	char		pre;
	int			base;
	int			hash;
}				t_args;

typedef struct	s_res
{
	char		*out;
	size_t		len;
	size_t		cap;
	size_t		size;
}				t_res;

/*
** --------------- ft_printf.c --------------
*/

int				ft_printf(const char *format, ...);
char			*handle_args(const char *fmt, char *place, t_res *res,
							va_list ap);

/*
** --------------- conversions.c --------------
*/

void			conversions(t_res *res, va_list ap, t_args *mod, char *spec);
char			*handle_conv(t_res *res, va_list ap, t_args *mod, char *spec);
char			*uox_conv(va_list ap, t_args *mod, char *spec, char *s);
char			*char_conv(t_res *res, va_list ap);
char			*pointer_conv(t_res *res, va_list ap);

/*
** --------------- modifiers.c --------------
*/

void			init_mods(t_args *mod);
char			*search_mods(va_list ap, t_args *mod, char *spec);
char			*handle_flags(va_list ap, t_args *mod, char *spec);
char			*add_padding(char *s, int len, t_args *mod);
char			*string_prec(char *s, t_args *mod);
char			*add_prefix(char *s, t_args *mod);
char			*diuox_prec(char *s, int len, t_args *mod);

/*
** --------------- handle_length.c --------------
*/

char			*handle_length(t_args *mod, char *spec);
intmax_t		uox_len(va_list ap, t_args *mod);
intmax_t		di_len(va_list ap, t_args *mod);

/*
** --------------- build.c --------------
*/

t_res			*init_res(size_t cap);
int				resize_res(t_res *res, size_t size);
void			check_res(t_res *res, size_t size);

#endif
