/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:24:26 by lyoung            #+#    #+#             */
/*   Updated: 2017/04/20 13:51:58 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_args(const char *fmt, va_list ap, char *place)
{
	char	conv;
	char	*str;
	int		nb;

	conv = *(place + 1);
	if (place - fmt)
	{
		str = ft_strndup(fmt, place - fmt);
		ft_putstr(str);
	}
	if (conv == 's')
	{
		str = va_arg(ap, char*);
		ft_putstr(str);
		return ;
	}
	else if (conv == 'd')
	{
		nb = va_arg(ap, int);
		ft_putnbr(nb);
		return ;
	}
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	char		*place;

	va_start(ap, fmt);
	if ((place = ft_strchr(fmt, '%')))
		handle_args(fmt, ap, place);
	va_end(ap);
	return (0);
}
