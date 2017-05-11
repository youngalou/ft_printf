/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 11:35:29 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/11 15:09:34 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*search_mods(char *spec, t_args *mod)
{
	int		length;

	length = 0;
	while (F_MOD)
	{
		if (*spec == 'h')
		{
			if (*(spec + 1) == 'h')
			{
				(length < 1) ? length = 1 : 0;
				spec++;
			}
			else
				(length < 2) ? length = 2 : 0;
			spec++;
		}
		else if (*spec == 'l')
		{
			if (*(spec + 1) == 'l')
			{
				(length < 3) ? length = 3 : 0;
				spec++;
			}
			(length < 4) ? length = 4 : 0;
			spec++;
		}
		else if (*spec == 'z')
		{
			(length < 5) ? length = 5 : 0;
			spec++;
		}
		else if (*spec == 'j')
		{
			(length < 6) ? length = 6 : 0;
			spec++;
		}
	}
	mod->length = length;
	return (spec);
}

intmax_t	uox_len(va_list ap, t_args *mod)
{
	if (mod->length == 0)
		return (va_arg(ap, unsigned int));
	else if (mod->length == 1)
		return ((unsigned char)va_arg(ap, unsigned int));
	else if (mod->length == 2)
		return ((unsigned short)va_arg(ap, unsigned int));
	else if (mod->length == 3)
		return ((long)va_arg(ap, unsigned int));
	else if (mod->length == 4)
		return ((long long)va_arg(ap, unsigned int));
	else if (mod->length == 5)
		return ((size_t)va_arg(ap, unsigned int));
	else if (mod->length == 6)
		return ((intmax_t)va_arg(ap, unsigned int));
	return (0);
}

intmax_t	di_len(va_list ap, t_args *mod)
{
	if (mod->length == 0)
		return (va_arg(ap, int));
	else if (mod->length == 1)
		return ((signed char)va_arg(ap, unsigned int));
	else if (mod->length == 2)
		return ((short)va_arg(ap, unsigned int));
	else if (mod->length == 3)
		return ((long)va_arg(ap, unsigned int));
	else if (mod->length == 4)
		return ((long long)va_arg(ap, unsigned int));
	else if (mod->length == 5)
		return ((size_t)va_arg(ap, unsigned int));
	else if (mod->length == 6)
		return ((intmax_t)va_arg(ap, unsigned int));
	return (0);
}
