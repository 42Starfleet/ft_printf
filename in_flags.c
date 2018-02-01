/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 02:37:47 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/31 02:37:47 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	in_flags(t_bag *bag, char c)
{
	char	*all_possible_flags;

	if (bag->zero == 0)
		all_possible_flags = "#-+ 0";
	else
		all_possible_flags = "#-+ ";
	while (*all_possible_flags)
	{
		if (c == *all_possible_flags)
			return (1);
		all_possible_flags++;
	}
	return (0);
}
