/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:03:19 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/08 12:30:38 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    string_conv(t_res *res, va_list ap)
{
    char    *s;

    s = va_arg(ap, char*);
	ft_strcat(res->out, s);
}

void    decimal_conv(t_res *res, va_list ap)
{
    char    *s;

    s = ft_itoa(va_arg(ap, int));
	ft_strcat(res->out, s);
}

void    char_conv(t_res *res, va_list ap)
{
    char    s[2];

    s[0] = va_arg(ap, int);
    s[1] = '\0';
	ft_strcat(res->out, s);
}

void	unsigned_int_conv(t_res *res, va_list ap)
{
	char	*s;

	s = ft_itoa(va_arg(ap, unsigned int));
	ft_strcat(res->out, s);
}

void	unsigned_hex_conv(t_res *res, va_list ap)
{
	char	*s;

	s = ft_itoa_base(va_arg(ap, unsigned int), 16);
	ft_strcat(res->out, s);
}

void	unsigned_oct_conv(t_res *res, va_list ap)
{
	char	*s;

	s = ft_itoa_base(va_arg(ap, unsigned int), 8);
	ft_strcat(res->out, s);
}
