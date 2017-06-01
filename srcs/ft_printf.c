/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:24:26 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/01 12:34:44 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*handle_args(t_res *res, va_list ap, t_args *mod)
{
	char	*spec;

	spec = res->place + 1;
	init_mods(mod);
	if (res->place - res->fmt)
	{
		check_res(res, res->place - res->fmt);
		ft_strncat(res->out, res->fmt, res->place - res->fmt);
		res->len += res->place - res->fmt;
	}
	if (F_MOD)
		spec = search_mods(ap, mod, spec);
	if (F_CONV)
		spec = conversions(res, ap, mod, spec);
	else if (*spec)
	{
		mod->tmp = add_padding(ft_strndup(spec, 1), mod->width - 1, mod);
		res->len += (mod->width) ? mod->width : 1;
		ft_strcat(res->out, mod->tmp);
		ft_strdel(&mod->tmp);
		spec++;
	}
	return (spec);
}

void	replace_null(t_res *res)
{
	int		i;

	i = 0;
	while (res->out[i])
	{
		if (res->out[i] == 127)
			res->out[i] = 0;
		i++;
	}
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_res		*res;
	t_args		*mod;
	size_t		ret;

	va_start(ap, fmt);
	res = init_res(50);
	mod = (t_args*)malloc(sizeof(t_args));
	res->start = ft_strdup(fmt);
	res->fmt = res->start;
	while ((res->place = ft_strchr(res->fmt, '%')))
		res->fmt = handle_args(res, ap, mod);
	if (ft_strlen(res->fmt))
	{
		ft_strcat(res->out, res->fmt);
		res->len += ft_strlen(res->fmt);
	}
	va_end(ap);
	replace_null(res);
	write(1, res->out, res->len);
	ret = res->len;
	free_res(res);
	free(mod);
	return (ret);
}
