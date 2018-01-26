/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:47:29 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/26 00:47:29 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	set_flags(t_bag *bag, char c)
{
	if (c == '#')
		bag->number_sign = 1;
	if (c == '-')
	{
		bag->minus = 1;
		if (bag->zero == 1)
			bag->zero = 0;
	}
	if (c == '+')
	{
		bag->plus = 1;
		if (bag->zero == 1)
			bag->zero = 0;
	}
	if (c == ' ')
		bag->space = 1;
	if (c == '0' && bag->minus != 1 && bag->plus != 1)
		bag->zero = 1;
	return (1);
}
