/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:03:19 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/31 12:33:28 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char	*conversions(t_res *res, va_list ap, t_args *mod, char *spec)
{
	char	*s;

	s = handle_conv(res, ap, mod, spec);
	res->size = ((*s == '\0' && (*spec == 'c' || *spec == 'C'))
				? 1 : ft_strlen(s));
	s = add_padding(s, mod->width - res->size, mod);
	res->len += ft_strlen(s);
	check_res(res, ft_strlen(s));
	ft_strcat(res->out, s);
	init_mods(mod);
	//ft_strdel(&s);
	return (spec + 1);
}

char	*handle_conv(t_res *res, va_list ap, t_args *mod, char *spec)
{
	char	*s;

	s = NULL;
	if (*spec == '%')
		s = "%\0";
	if (F_CAPS && mod->length < 3)
		mod->length = 3;
	if (F_UOX || *spec == 'd' || *spec == 'D' || *spec == 'i')
		s = handle_diuox(res, ap, mod, spec);
	else if (*spec == 's' || *spec == 'S' || *spec == 'c'
			|| *spec == 'C' || *spec == 'p')
		s = handle_scp(res, ap, mod, spec);
	return (s);
}
