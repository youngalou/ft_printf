/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 11:35:29 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/11 14:12:06 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*search_mods(char *place, t_args *mod)
{
	int		length;

	length = 0;
	while (*place == 'h' || *place == 'l' || *place == 'z' || *place == 'j')
	{
		if (*place == 'h')
		{
			if (*(place + 1) == 'h')
			{
				(length < 1) ? length = 1 : 0;
				place++;
			}
			else
				(length < 2) ? length = 2 : 0;
			place++;
		}
		else if (*place == 'l')
		{
			if (*(place + 1) == 'l')
			{
				(length < 3) ? length = 3 : 0;
				place++;
			}
			(length < 4) ? length = 4 : 0;
			place++;
		}
		else if (*place == 'z')
		{
			(length < 5) ? length = 5 : 0;
			place++;
		}
		else if (*place == 'j')
		{
			(length < 6) ? length = 6 : 0;
			place++;
		}
	}
	mod->length = length;
	return (place);
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
