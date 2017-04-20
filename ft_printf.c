/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:24:26 by lyoung            #+#    #+#             */
/*   Updated: 2017/04/20 13:14:53 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*void	handle_args(char *str, char c)
{
	if (c == 's')
	{
		ft_putstr(str);
		return ;
	}
	if (c == 'd')
	{
		ft_putnbr(str);
		return ;
	}
}*/

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*place;
	char		*str;
	int			nb;
	char		c;

	va_start(ap, format);
	while (*format)
	{
		if ((place = ft_strchr(format, '%')))
		{
			if (*(place + 1) == 's')
			{
				str = va_arg(ap, char*);
				ft_putstr(str);
				return (0);
			}
			if (*(place + 1) == 'd')
			{
				nb = va_arg(ap, int);
				ft_putnbr(nb);
				return (0);
			}
			if (*(place + 1) == 'c')
			{
				c = va_arg(ap, char);
				ft_putchar(c);
				return (0);
			}
		}
		if (ft_strlen(format) > 0)
			ft_putstr(format);
		va_end(ap);
	}
	return (0);
}
