/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:24:26 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/01 16:23:28 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_to_string(const char *fmt, char **str)
{
	char	*tmp;

	tmp = ft_strjoin(*str, fmt);
	free(*str);
	*str = tmp;
	//free(tmp);
}

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
	//free(tmp);
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
	free(s);
	free(*str);
	*str = tmp;
	free(tmp); //why do I have to free tmp here but nowhere else??
}

void	char_conv(char **str, va_list ap)
{
	char	s[2];
	char	*tmp;

	s[0] = va_arg(ap, int);
	s[1] = '\0';
	if (!str)
	{
		*str = ft_strdup(s);
		return ;
	}
	tmp = ft_strjoin(*str, s);
	free(*str);
	*str = tmp;
	//free(tmp);
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
	else if (conv == 'd' || conv == 'i')
	{
		decimal_conv(str, ap);
		return ;
	}
	else if (conv == 'c')
	{
		char_conv(str, ap);
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
	if (ft_strlen(fmt))
		add_to_string(fmt, &str);
	ft_putstr(str);
	va_end(ap);
	return (0);
}
