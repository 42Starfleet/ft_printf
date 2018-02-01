/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 02:38:01 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/31 02:38:01 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long		power_l(long number, int exponent)
{
	long	result;

	result = 1;
	if (exponent == 0)
		return (result);
	while (exponent--)
		result = result * number;
	return (result);
}
