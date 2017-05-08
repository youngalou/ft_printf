/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 11:35:29 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/08 15:59:24 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*search_mods(char *place, t_args *mod)
{
	int		length;

	length = 0;
	while (*place == 'h' || *place == 'l' || *place == 'z' || *place == 'j')
	{
		if (*place == 'h')
		{
			if (*(place + 1) == 'h')
			{
				(length < 2) ? length = 2 : 0;
				place++;
			}
			(length < 1) ? length = 1 : 0;
			place++;
		}
		else if (*place == 'l')
		{
			if (*(place + 1) == 'l')
			{
				(length < 3) ? length = 3 : 0;
				place++;
			}
			(length < 4) ? length = 4 : 0;
			place++;
		}
		else if (*place == 'z')
		{
			(length < 5) ? length = 5 : 0;
			place++;
		}
		else if (*place == 'j')
		{
			(length < 6) ? length = 6 : 0;
			place++;
		}
	}
	mod->length = length;
	return (place);
}
