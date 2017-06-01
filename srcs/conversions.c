/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:03:19 by lyoung            #+#    #+#             */
/*   Updated: 2017/06/01 13:00:20 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*conversions(t_res *res, va_list ap, t_args *mod, char *spec)
{
	char	*s;

	s = handle_conv(res, ap, mod, spec);
	if (!s)
		return (spec + 1);
	res->size = ((*s == '\0' && (*spec == 'c' ||
				*spec == 'C')) ? 1 : ft_strlen(s));
	s = add_padding(s, mod->width - res->size, mod);
	res->len += ft_strlen(s);
	check_res(res, ft_strlen(s));
	ft_strcat(res->out, s);
	init_mods(mod);
	ft_strdel(&s);
	return (spec + 1);
}

char	*handle_conv(t_res *res, va_list ap, t_args *mod, char *spec)
{
	char	*s;

	s = NULL;
	if (*spec == '%')
		s = ft_strdup("%");
	if (F_CAPS && mod->length < 3)
		mod->length = 3;
	if (F_UOX || F_DI || F_CAPS)
		s = handle_diuox(res, ap, mod, spec);
	else if (F_SCP)
		s = handle_scp(res, ap, mod, spec);
	return (s);
}
