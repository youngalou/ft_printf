/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uinttoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 12:38:04 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/22 12:16:46 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_uinttoa_base(uintmax_t value, int base)
{
	uintmax_t	nb;
	uintmax_t	base_var;
	int			digit;
	char		*ret;

	nb = value;
	base_var = 1;
	digit = 0;
	if (nb == 0)
		return("0\0");
	while (nb >= base_var)
	{
		base_var = base * base_var;
		digit++;
	}
	ret = (char*)malloc(sizeof(ret) * (digit + 1));
	ret[digit] = '\0';
	digit--;
	while (nb > 0)
	{
		if (nb % base > 9)
			ret[digit] = (nb % base) + 55;
		else
			ret[digit] = (nb % base) + '0';
		digit--;
		nb = nb / base;
	}
	return (ret);
}
