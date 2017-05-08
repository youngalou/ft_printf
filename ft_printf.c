/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:24:26 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/08 13:59:33 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_args(const char *fmt, va_list ap, char *spec, t_res *res)
{
	char	*conv;
	t_args	*mod;

	conv = spec + 1;
	mod = (t_args*)malloc(sizeof(t_args));
	if (spec - fmt)
	{
		if (!res->out)
		{
			ft_strncpy(res->out, fmt, spec - fmt);
			res->len = spec - fmt;
		}
		else
		{
			check_res(res, spec - fmt);
			ft_strncat(res->out, fmt, spec - fmt);
			res->len = ft_strlen(res->out);
		}
	}
	if (*conv == 'h' || *conv == 'l' || *conv == 'z' || *conv == 'j')
		conv = search_mods(conv, mod);
	if (*conv == 's' || *conv == 'd' || *conv == 'i' || *conv == 'c'
			|| *conv == 'u' || *conv == 'x' || *conv == 'o')
		handle_conv(conv, ap, res);
	return (conv + 1);
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	char		*spec;
	t_res		*res;

	va_start(ap, fmt);
	res = init_res(50);
	while ((spec = ft_strchr(fmt, '%')))
		fmt = handle_args(fmt, ap, spec, res);
	if (ft_strlen(fmt))
		ft_strcat(res->out, fmt);
	ft_putstr(res->out);
	va_end(ap);
	return (ft_strlen(res->out));
}
