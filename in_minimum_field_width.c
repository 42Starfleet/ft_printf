/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_minimum_field_width.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:47:06 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/26 00:47:07 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	in_minimum_field_width(char c)
{
	if (ft_isdigit(c))
		return (1);
	return (0);
}
