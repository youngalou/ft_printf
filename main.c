/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 13:41:44 by lyoung            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/05/25 14:46:01 by lyoung           ###   ########.fr       */
=======
/*   Updated: 2017/05/25 14:27:49 by lyoung           ###   ########.fr       */
>>>>>>> 9d56cb9... All basic tests passed!
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		main(void)
{
<<<<<<< HEAD
	uintmax_t	nb;

	nb = ULLONG_MAX;
	printf("ft_printf: %d\n", ft_printf("[ft_printf = %zo]\n", nb));
	printf("printf:    %d\n", printf("[printf    = %zo]\n", nb));
=======
	intmax_t	nb;

	nb = -9223372036854775808;
	ft_printf("[ft_printf = %lld]\n", nb);
	printf("[printf    = %ld]\n", nb);
>>>>>>> 9d56cb9... All basic tests passed!
	return (0);
}
