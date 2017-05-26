/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 11:35:29 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/26 14:16:04 by lyoung           ###   ########.fr       */
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
	else if (*spec == '0' && mod->align == 0 && mod->prec == -1)
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
		mod->pad = ' ';
	}
	else if ((*spec == ' ' || *spec == '+') && mod->pre != '+')
		mod->pre = *spec;
	else if (*spec =='#')
		mod->hash = 4;
	else if (*spec >= '1' && *spec <= '9')
	{
		mod->width = ft_atoi(spec);
		while (*(spec + 1) >= '0' && *(spec + 1) <= '9')
			spec++;
	}
	return (spec + 1);
}

char		*string_prec(char *s, t_args *mod)
{
	char	*tmp;

	if (mod->prec == -1)
		return (s);
	tmp = ft_strndup(s, mod->prec);
	//ft_strdel(&s);
	return (tmp);
}

char		*diuox_prec(char *s, int len, t_args *mod)
{
	char	*padding;
	char	*tmp;
	char	pre[2];

	if (*s == '0' && mod->hash != 1)
		s = string_prec(s, mod);
	if (len < 1)
		return (s);
	pre[0] = mod->pre;
	pre[1] = '\0';
	(mod->pre == '-') ? s++ : 0;
	padding = (char*)malloc(len + 1);
	padding[len] = '\0';
	len--;
	while (len >= 0)
	{
		padding[len] = '0';
		len--;
	}
	tmp = NULL;
	tmp = ft_strjoin(padding, s);
	//ft_strdel(&s);
	s = tmp;
	if (pre[0] == '-')
		tmp = ft_strjoin(pre, s);
	s = tmp;
	//ft_strdel(&padding);
	return (s);
}

char		*add_padding(char *s, int len, t_args *mod)
{
	char	*padding;
	char	*tmp;
	char	*pre;

	if (len < 1)
		return (s);
	pre = move_prefix(mod);
	(mod->pre && mod->pad == '0') ? s++ : 0;
	(mod->hash > 1 && mod->pad == '0') ? s++ : 0;
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
	if (pre && mod->pad == '0')
		tmp = ft_strjoin(pre, s);
	s = tmp;
	//ft_strdel(&padding);
	return (s);
}

char		*move_prefix(t_args *mod)
{
	char	*pre;

	if (mod->hash == 0 && mod->pre == -1)
		return (NULL);
	pre = (char*)malloc(3);
	pre[0] = mod->pre;
	pre[1] = '\0';
	if (mod->hash == 2)
		pre[1] = 'x';
	else if (mod->hash == 3)
		pre[1] = 'X';
	pre[2] = '\0';
	return (pre);
}

char		*add_prefix(char *s, t_args *mod)
{
	char	pre[2];
	char	*tmp;
	int		i;

	i = 0;
	while (s[i])
	{
		if (!mod->pre || s[i] == '-')
			return (s);
		i++;
	}
	pre[0] = mod->pre;
	pre[1] = '\0';
	tmp = ft_strjoin(pre, s);
	//ft_strdel(&s);
	return (tmp);
}

char		*add_hash(char *s, t_args *mod)
{
	char	pre[3];
	char	*tmp;

	if (!mod->hash || !*s || (ft_strcmp(s, "0") == 0 && mod->addr == 0))
		return (s);
	mod->pre = '0';
	pre[0] = mod->pre;;
	pre[1] = '\0';
	if (mod->hash == 2)
		pre[1] = 'x';
	else if (mod->hash == 3)
		pre[1] = 'X';
	pre[2] = '\0';
	tmp = ft_strjoin(pre, s);
	//ft_strdel(&s);
	return (tmp);
}

