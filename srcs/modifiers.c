/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 11:35:29 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/22 14:40:33 by lyoung           ###   ########.fr       */
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
	if (*spec == '*')
	{
		mod->width = va_arg(ap, unsigned int);
		mod->pad = ' ';
	}
	else if (*spec == '-')
		mod->align = 1;
	else if (*spec == '0' && mod->align == 0)
		mod->pad = '0';
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
	}
	else if ((*spec == ' ' || *spec == '+') && mod->pre != '+')
		mod->pre = *spec;
	else if (*spec >= '1' && *spec <= '9')
	{
		mod->width = ft_atoi(spec);
		while (*(spec + 1) >= '0' && *(spec + 1) <= '9')
			spec++;
	}
	return (spec + 1);
}

char		*handle_prec(char *s, t_args *mod)
{
	char	*tmp;

	if (mod->prec == -1)
		return (s);
	tmp = ft_strndup(s, mod->prec);
	//ft_strdel(&s);
	return (tmp);
}

char		*add_padding(char *s, int len, t_args *mod)
{
	char	*padding;
	char	*tmp;

	if (len < 1)
		return (s);
	padding = (char*)malloc(len + 1);
	padding[len] = '\0';
	len--;
	while (len >= 0)
	{
		padding[len] = mod->pad;
		len--;
	}
	tmp = NULL;
	if (mod->align == 0)
		tmp = ft_strjoin(padding, s);
	else if (mod->align == 1)
		tmp = ft_strjoin(s, padding);
	//ft_strdel(&s);
	s = tmp;
	//ft_strdel(&padding);
	return (s);
}

char		*add_prefix(char *s, t_args *mod)
{
	char	pre[2];
	char	*tmp;

	if (!mod->pre || *s == '-')
		return (s);
	pre[0] = mod->pre;
	pre[1] = '\0';
	tmp = ft_strjoin(pre, s);
	//ft_strdel(&s);
	return (tmp);
}
