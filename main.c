/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 13:41:44 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/25 14:46:01 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		main(void)
{
	uintmax_t	nb;

	nb = ULLONG_MAX;
	printf("ft_printf: %d\n", ft_printf("[ft_printf = %zo]\n", nb));
	printf("printf:    %d\n", printf("[printf    = %zo]\n", nb));
	return (0);
}
