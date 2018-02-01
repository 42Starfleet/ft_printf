/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 02:37:59 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/31 02:38:00 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		power_i(int number, int exponent)
{
	int	result;

	result = 1;
	if (exponent == 0)
		return (result);
	while (exponent--)
		result = result * number;
	return (result);
}
