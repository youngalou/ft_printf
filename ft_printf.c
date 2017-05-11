/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:24:26 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/11 11:20:27 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_args(const char *fmt, char *place, t_res *res, va_list ap)
{
	char	*spec;
	t_args	*mod;

	spec = place + 1;
	mod = (t_args*)malloc(sizeof(t_args));
	if (place - fmt)
	{
		if (!res->out)
		{
			ft_strncpy(res->out, fmt, place - fmt);
			res->len = place - fmt;
		}
		else
		{
			check_res(res, place - fmt);
			ft_strncat(res->out, fmt, place - fmt);
			res->len = ft_strlen(res->out);
		}
	}
	if (F_MOD)
		spec = search_mods(spec, mod);
	if (F_CONV)
		handle_conv(spec, res, ap, mod);
//	ft_putnbr(mod->length);
//	ft_putchar('\n');
	return (spec + 1);
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
		ft_strcat(res->out, fmt);
	ft_putstr(res->out);
	va_end(ap);
	return (ft_strlen(res->out));
}
