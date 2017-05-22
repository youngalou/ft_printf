/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:03:19 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/22 14:05:53 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	conversions(t_res *res, va_list ap, t_args *mod, char *spec)
{
	char	*s;

	s = handle_conv(res, ap, mod, spec);
	s = add_prefix(s, mod);
	res->size = ((*s == '\0' && (*spec == 'c' || *spec == 'C')) ? 1 : ft_strlen(s));
	s = add_padding(s, mod->width - res->size, mod);
	res->len += ft_strlen(s);
	check_res(res, ft_strlen(s));
	ft_strcat(res->out, s);
	//ft_strdel(&s);
}

char	*handle_conv(t_res *res, va_list ap, t_args *mod, char *spec)
{
	char	*s;

	s = NULL;
	if (F_CAPS && mod->length < 3)
		mod->length = 3;
	if (*spec == '%')
		s = "%\0";
	else if (*spec == 's' || *spec == 'S')
	{
		s = va_arg(ap, char*);
		if (!s)
			s = "(null)";
		s = handle_prec(s, mod);
	}
	else if (*spec == 'd' || *spec == 'D' || *spec == 'i')
		s = ft_itoa(di_len(ap, mod));
	else if (*spec == 'c' || *spec == 'C')
		s = char_conv(res, ap);
	else if (F_UOX)
		s = uox_conv(ap, mod, spec, s);
	else if (*spec == 'p')
		s = pointer_conv(res, ap);
	return (s);
}

char	*uox_conv(va_list ap, t_args *mod, char *spec, char *s)
{
	int		i;

	if (*spec == 'u' || *spec == 'U')
		mod->base = 10;
	else if (*spec == 'o' || *spec == 'O')
		mod->base = 8;
	else if (*spec == 'x' || *spec == 'X')
		mod->base = 16;
	s = ft_itoa_base(uox_len(ap, mod), mod->base);
	if (mod->prec == 0)
		s = "\0";
	if (*spec == 'X' && *s != '0')
	{
		i = 0;
		while (s[i])
		{
			s[i] = ft_toupper(s[i]);
			i++;
		}
	}
	return (s);
}

char	*char_conv(t_res *res, va_list ap)
{
	char	*s;

	s = (char*)malloc(2);
	s[0] = va_arg(ap, int);
	s[1] = '\0';
	if (!s[0])
		res->len++;
	return (s);
}

char	*pointer_conv(t_res *res, va_list ap)
{
	char	*pre;
	char	*s;

	pre = "0x\0";
	s = ft_itoa_base(va_arg(ap, long long), 16);
	check_res(res, ft_strlen(pre));
	ft_strcat(res->out, pre);
	return (s);
}
