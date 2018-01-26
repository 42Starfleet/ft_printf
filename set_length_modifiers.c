/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_length_modifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:47:30 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/26 00:47:30 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_types(char **new)
{
	new[0] = "hh";
	new[1] = "h";
	new[2] = "l";
	new[3] = "ll";
	new[4] = "j";
	new[5] = "z";
}

char		**set_length_modifiers_array(void)
{
	char	**new;
	int		number_of_length_modifiers;

	number_of_length_modifiers = 6;
	new = malloc(sizeof(char **) * (number_of_length_modifiers + 1));
	new[number_of_length_modifiers] = 0;
	set_types(new);
	return (new);
}
