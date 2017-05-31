/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 11:35:29 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/31 14:33:02 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void		init_mods(t_args *mod)
{
	mod->length = 0;
	mod->width = 0;
	mod->prec = -1;
	mod->align = 0;
	mod->pad = ' ';
	mod->pre = 0;
	mod->base = 10;
	mod->hash = 0;
	mod->addr = 0;
	mod->tmp = 0;
}

char		*search_mods(va_list ap, t_args *mod, char *spec)
{
	while (F_MOD)
	{
		while (F_LEN)
			spec = handle_length(mod, spec);
		while (F_FLAGS)
			spec = handle_flags(ap, mod, spec);
	}
	return (spec);
}

char		*handle_flags(va_list ap, t_args *mod, char *spec)
{
	if (*spec == '*' || *spec == '.')
		spec = width_prec(ap, mod, spec);
	else if (*spec == '-')
	{
		mod->align = 1;
		mod->pad = ' ';
	}
	else if (*spec == '0' && mod->align == 0 && mod->prec == -1)
		mod->pad = '0';
	else if ((*spec == ' ' || *spec == '+') && mod->pre != '+')
		mod->pre = *spec;
	else if (*spec == '#')
		mod->hash = 4;
	else if (*spec >= '1' && *spec <= '9')
	{
		mod->width = ft_atoi(spec);
		while (*(spec + 1) >= '0' && *(spec + 1) <= '9')
			spec++;
	}
	return (spec + 1);
}

char		*width_prec(va_list ap, t_args *mod, char *spec)
{
	if (*spec == '*')
	{
		mod->width = va_arg(ap, int);
		if (mod->width < 0)
		{
			mod->width = mod->width * -1;
			mod->align = 1;
		}
	}
	else if (*spec == '.')
	{
		if (*(spec + 1) == '*')
		{
			mod->prec = va_arg(ap, unsigned int);
			spec++;
		}
		else
		{
			mod->prec = ft_atoi(spec + 1);
			while (*(spec + 1) >= '0' && *(spec + 1) <= '9')
				spec++;
		}
		mod->pad = ' ';
	}
	return (spec);
}
