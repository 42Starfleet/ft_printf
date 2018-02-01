/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_minimum_field_width.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 02:37:51 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/31 02:37:52 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	in_minimum_field_width(char c)
{
	if (ft_isdigit(c))
		return (1);
	return (0);
}
