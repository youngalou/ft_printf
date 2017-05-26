/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:24:26 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/25 16:30:03 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*handle_args(const char *fmt, char *place, t_res *res, va_list ap)
{
	char	*spec;
	t_args	*mod;

	spec = place + 1;
	mod = (t_args*)malloc(sizeof(t_args));
	init_mods(mod);
	if (place - fmt)
	{
		check_res(res, place - fmt);
		ft_strncat(res->out, fmt, place - fmt);
		res->len += place - fmt;
	}
	if (F_MOD)
		spec = search_mods(ap, mod, spec);
	if (F_CONV)
		spec = conversions(res, ap, mod, spec);
	return (spec);
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	char		*place;
	t_res		*res;

	va_start(ap, fmt);
	res = init_res(50);
	while ((place = ft_strchr(fmt, '%')))
		fmt = handle_args(fmt, place, res, ap);
	if (ft_strlen(fmt))
	{
		ft_strcat(res->out, fmt);
		res->len += ft_strlen(fmt);
	}
	va_end(ap);
	ft_putstr(res->out);
	return (res->len);
}
