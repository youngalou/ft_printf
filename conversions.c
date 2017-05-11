/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:03:19 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/11 14:48:25 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_conv(char *spec, t_res *res, va_list ap, t_args *mod)
{
	if (*spec == '%')
	{
		percent_conv(res, ap);
		return ;
	}
	if (F_CAPS && mod->length < 3)
		mod->length = 3;
	if (*spec == 's' || *spec == 'S')
	{
		string_conv(res, ap, mod);
		return ;
	}
	else if (*spec == 'd' || *spec == 'D' || *spec == 'i')
	{
		decimal_conv(res, ap, mod);
		return ;
	}
	else if (*spec == 'c' || *spec == 'C')
	{
		char_conv(res, ap, mod);
		return ;
	}
	else if (*spec == 'u' || *spec == 'U')
	{
		unsigned_int_conv(res, ap, mod);
		return ;
	}
	else if (*spec == 'o' || *spec == 'O')
	{
		unsigned_oct_conv(res, ap, mod);
		return ;
	}
	else if (*spec == 'x' || *spec == 'X')
	{
		unsigned_hex_conv(res, ap, *spec, mod);
		return ;
	}
	else if (*spec == 'p')
	{
		pointer_conv(res, ap);
		return ;
	}
}

void	percent_conv(t_res *res, va_list ap)
{
	char	*s;

	s = "%\0";
	ft_strcat(res->out, s);
}

void	string_conv(t_res *res, va_list ap, t_args *mod)
{
	char	*s;

	s = va_arg(ap, char*);
	ft_strcat(res->out, s);
}

void	decimal_conv(t_res *res, va_list ap, t_args *mod)
{
	char	*s;

	s = ft_itoa(di_len(ap, mod));
	ft_strcat(res->out, s);
}

void	char_conv(t_res *res, va_list ap, t_args *mod)
{
	char	s[2];

	s[0] = va_arg(ap, int);
	s[1] = '\0';
	ft_strcat(res->out, s);
}


void	unsigned_int_conv(t_res *res, va_list ap, t_args *mod)
{
	char	*s;

	s = ft_itoa(uox_len(ap, mod));
	ft_strcat(res->out, s);
}

void	unsigned_oct_conv(t_res *res, va_list ap, t_args *mod)
{
	char	*s;

	s = ft_itoa_base(uox_len(ap, mod), 8);
	ft_strcat(res->out, s);
}

void	unsigned_hex_conv(t_res *res, va_list ap, char conv, t_args *mod)
{
	char	*s;
	int		i;

	s = ft_itoa_base(uox_len(ap, mod), 16);
	if (conv == 'X')
	{
		i = 0;
		while (s[i])
		{
			s[i] = ft_toupper(s[i]);
			i++;
		}
	}
	ft_strcat(res->out, s);
}

void	pointer_conv(t_res *res, va_list ap)
{
	char	*pre;
	char	*s;

	pre = "0x\0";
	s = ft_itoa_base(va_arg(ap, long long), 16);
	ft_strcat(res->out, pre);
	ft_strcat(res->out, s);
}
