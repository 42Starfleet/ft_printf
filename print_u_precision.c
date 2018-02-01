/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 02:38:33 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/31 02:38:33 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_u_precision(t_bag *bag, char *input)
{
	if (bag->period)
	{
		if (bag->precision == 0 && number_cmp(input, "0") == 0)
		{
			input = "";
			return (input);
		}
		if (number_cmp(input, "0") < 0)
		{
			input = input + 1;
			input = pad_left(input, bag->precision, '0');
			input = ft_strjoin("-", input);
		}
		else
			input = pad_left(input, bag->precision, '0');
		bag->zero = 0;
	}
	return (input);
}
