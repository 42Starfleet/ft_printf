/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_length_modifiers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 02:37:50 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/31 02:37:50 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	in_length_modifiers(char **length_modifiers, char *length_modifier)
{
	while (*length_modifiers)
	{
		if (ft_strstr(*length_modifiers, length_modifier))
			return (1);
		length_modifiers++;
	}
	return (0);
}
