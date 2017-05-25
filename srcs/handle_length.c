/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 10:53:12 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/25 10:56:32 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

char		*handle_length(t_args *mod, char *spec)
{
	if (*spec == 'h')
	{
		if (*(spec + 1) == 'h')
		{
			(mod->length < 1) ? mod->length = 1 : 0;
			spec++;
		}
		else
			(mod->length < 2) ? mod->length = 2 : 0;
	}
	else if (*spec == 'l')
	{
		if (*(spec + 1) == 'l')
		{
			(mod->length < 4) ? mod->length = 4 : 0;
			spec++;
		}
		(mod->length < 3) ? mod->length = 3 : 0;
	}
	else if (*spec == 'z')
		(mod->length < 5) ? mod->length = 5 : 0;
	else if (*spec == 'j')
		(mod->length < 6) ? mod->length = 6 : 0;
	spec++;
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
		return ((long)va_arg(ap, unsigned long));
	else if (mod->length == 4)
		return ((long long)va_arg(ap, unsigned int)); //should be unsigned long long, but can't make datatype any >
	else if (mod->length == 5)
		return ((size_t)va_arg(ap, size_t));
	else if (mod->length == 6)
		return ((intmax_t)va_arg(ap, uintmax_t));
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
		return ((long)va_arg(ap, long));
	else if (mod->length == 4)
		return ((long long)va_arg(ap, long long));
	else if (mod->length == 5)
		return ((size_t)va_arg(ap, size_t));
	else if (mod->length == 6)
		return ((intmax_t)va_arg(ap, intmax_t));
	return (0);
}
