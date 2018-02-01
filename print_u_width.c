/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 02:38:34 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/31 02:38:35 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_u_width(t_bag *bag, char *input)
{
	char pad_character;

	pad_character = ' ';
	if (bag->width)
	{
		if (bag->zero)
			pad_character = '0';
		if (!bag->minus)
			input = pad_left(input, bag->width, pad_character);
		if (bag->minus)
			input = pad_right(input, bag->width, ' ');
		if (ft_strchr(input, '+') && pad_character == '0')
		{
			ft_strchr(input, '+')[0] = pad_character;
			input[0] = '+';
		}
		if (ft_strchr(input, '-') && pad_character == '0')
		{
			ft_strchr(input, '-')[0] = pad_character;
			input[0] = '-';
		}
		bag->minus = 0;
	}
	return (input);
}
