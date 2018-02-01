/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 20:39:58 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/31 02:38:47 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	set_flags(t_bag *bag, char c)
{
	if (c == '#')
		bag->number_sign = 1;
	if (c == '-')
		bag->minus = 1;
	if (c == '+')
		bag->plus = 1;
	if (c == ' ')
		bag->space = 1;
	if (c == '0')
		bag->zero = 1;
	return (1);
}
