/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uinttoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:38:04 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/25 14:15:15 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_uinttoa_base(uintmax_t value, int base)
{
	uintmax_t	nb;
	int			digit;
	char		*ret;

	nb = value;
	digit = 0;
	if (nb == 0)
		return ("0\0");
	while (value)
	{
		value = value / base;
		digit++;
	}
	ret = (char*)malloc(sizeof(ret) * (digit + 1));
	ret[digit] = '\0';
	digit--;
	while (nb > 0)
	{
		if (nb % base > 9)
			ret[digit] = nb % base + 87;
		else
			ret[digit] = nb % base + '0';
		nb = nb / base;
		digit--;
	}
	return (ret);
}
