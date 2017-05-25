/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 13:41:44 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/25 15:15:31 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		main(void)
{
	uintmax_t	nb;
	int			out1;
	int			out2;

	nb = ULLONG_MAX;

	out1 = printf("\t%zo, %zo\n", 0, ULLONG_MAX);
	out2 = ft_printf("\t%zo, %zo\n", 0, ULLONG_MAX);
	if (out1 != out2)
		printf("ERRROR\n");
	return (0);
}
