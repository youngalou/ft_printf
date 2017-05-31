/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 11:36:36 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/31 12:17:21 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

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
	while (--len >= 0)
		padding[len] = mod->pad;
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
	ft_strdel(&padding);
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
	ft_strdel(&s); //causes random errors with 'X'
	return (tmp);
}

char		*add_hash(char *s, t_args *mod)
{
	char	pre[3];
	char	*tmp;

	if (!mod->hash || ((!*s || (ft_strcmp(s, "0") == 0)) && mod->addr == 0))
		return (s);
	mod->pre = '0';
	pre[0] = mod->pre;
	pre[1] = '\0';
	if (mod->hash == 2)
		pre[1] = 'x';
	else if (mod->hash == 3)
		pre[1] = 'X';
	pre[2] = '\0';
	tmp = ft_strjoin(pre, s); //causes random errors with 'X'
	ft_strdel(&s);
	return (tmp);
}
