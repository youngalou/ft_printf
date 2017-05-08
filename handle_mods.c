/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 11:35:29 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/05 14:43:31 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	search_mods(char *place)
{
	t_args	arg;

    if (*place == 'h')
    {
        if (*(place + 1) == 'h')
            arg->length = 2;
        arg->length = 1;
    }
	else if (*place == 'l')
	{
		if (*(place + 1) == 'l')
			arg->length = 3;
		arg->length = 4;
	}
	else if (*place == 'z')
		arg->length = 5;
	else if (*place == 'j')
		arg->length = 6;
}
