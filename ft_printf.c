/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:24:26 by lyoung            #+#    #+#             */
/*   Updated: 2017/04/21 11:15:21 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	string_conv(char **str, va_list ap)
{
	char	*s;
	char	*tmp;

	s = va_arg(ap, char*);
	if (!*str)
	{
		*str = ft_strdup(s);
		return ;
	}
	tmp = ft_strjoin(*str, s);
	free(*str);
	*str = tmp;
	free(tmp);
}

void	decimal_conv(char **str, va_list ap)
{
	char	*s;
	char	*tmp;

	s = ft_itoa(va_arg(ap, int));
	if (!*str)
	{
		*str = ft_strdup(s);
		return ;
	}
	tmp = ft_strjoin(*str, s);
	free(*str);
	*str = tmp;
	free(tmp);
}

void	handle_args(const char *fmt, va_list ap, char *place, char **str)
{
	char	conv;
	char	*tmp;

	conv = *(place + 1);
	if (place - fmt)
	{
		if (!*str)
			*str = ft_strndup(fmt, place - fmt);
		else
		{
			tmp = ft_strnjoin(*str, fmt, place - fmt);
			free(*str);
			*str = tmp;
			//free(tmp);
		}
	}
	if (conv == 's')
	{
		string_conv(str, ap);
		return ;
	}
	else if (conv == 'd')
	{
		decimal_conv(str, ap);
		return ;
	}
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	char		*place;
	char		*str;

	va_start(ap, fmt);
	str = NULL;
	while ((place = ft_strchr(fmt, '%')))
	{
		handle_args(fmt, ap, place, &str);
		fmt = place + 2;
	}
	ft_putstr(str);
	va_end(ap);
	return (0);
}
