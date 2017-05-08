/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 13:41:44 by lyoung            #+#    #+#             */
/*   Updated: 2017/05/08 15:16:12 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	ft_printf("%s this is a test %s function which should output %llzhX\n", "Hello world,", "for my ft_printf", 127);
	return (0);
}
