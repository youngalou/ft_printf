/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:24:26 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/08 13:15:26 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_args(const char *fmt, va_list ap, char *spec, t_res *res)
{
	char	*conv;

	conv = spec + 1;
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
	if (*conv == 's' || *conv == 'd' || *conv == 'i' || *conv == 'c'
			|| *conv == 'u' || *conv == 'x' || *conv == 'o')
		handle_conv(conv, ap, res);
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	char		*spec;
	t_res		*res;

	va_start(ap, fmt);
	res = init_res(50);
	while ((spec = ft_strchr(fmt, '%')))
	{
		handle_args(fmt, ap, spec, res);
		fmt = spec + 2;
	}
	if (ft_strlen(fmt))
		ft_strcat(res->out, fmt);
	ft_putstr(res->out);
	va_end(ap);
	return (ft_strlen(res->out));
}
