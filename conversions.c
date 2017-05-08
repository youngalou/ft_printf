/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:03:19 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/08 15:15:53 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_conv(char *spec, t_res *res, va_list ap)
{
    if (*spec == 's')
    {
        string_conv(res, ap);
        return ;
    }
    else if (*spec == 'd' || *spec == 'i')
    {
        decimal_conv(res, ap);
        return ;
    }
    else if (*spec == 'c')
    {
        char_conv(res, ap);
        return ;
    }
    else if (*spec == 'u')
    {
        unsigned_int_conv(res, ap);
        return ;
    }
    else if (*spec == 'o')
    {
        unsigned_oct_conv(res, ap);
        return ;
    }
    else if (*spec == 'x' || *spec == 'X')
    {
        unsigned_hex_conv(res, ap, *spec);
        return ;
    }
}

void    string_conv(t_res *res, va_list ap)
{
    char    *s;

    s = va_arg(ap, char*);
	ft_strcat(res->out, s);
}

void    decimal_conv(t_res *res, va_list ap)
{
    char    *s;

    s = ft_itoa(va_arg(ap, int));
	ft_strcat(res->out, s);
}

void    char_conv(t_res *res, va_list ap)
{
    char    s[2];

    s[0] = va_arg(ap, int);
    s[1] = '\0';
	ft_strcat(res->out, s);
}

void	unsigned_int_conv(t_res *res, va_list ap)
{
	char	*s;

	s = ft_itoa(va_arg(ap, unsigned int));
	ft_strcat(res->out, s);
}

void	unsigned_oct_conv(t_res *res, va_list ap)
{
	char	*s;

	s = ft_itoa_base(va_arg(ap, unsigned int), 8);
	ft_strcat(res->out, s);
}

void	unsigned_hex_conv(t_res *res, va_list ap, char conv)
{
	char	*s;
	int		i;

	s = ft_itoa_base(va_arg(ap, unsigned int), 16);
	if (conv == 'x')
	{
		i = 0;
		while (s[i])
		{
			s[i] = ft_tolower(s[i]);
			i++;
		}
	}
	ft_strcat(res->out, s);
}
