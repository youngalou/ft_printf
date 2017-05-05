/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 11:35:29 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/04 12:21:14 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	search_mods(char *place)
{
	t_args	arg;

    if (*place == 'l')
    {
        if (*(place + 1) == 'l')
            arg->length = 'L';
        arg->length = 'l';
    }
	else if (*place == 'h')
	{
		if (*(place + 1) == 'h')
			arg->length = 'H';
		arg->length = 'h';
	}
	else if (*place == 'j')
		arg->length = 'j';
	else if (*place == 'z')
		arg->length = 'z';
}
