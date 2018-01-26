/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_variables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:47:26 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/26 00:47:27 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_t_bag_variables(t_bag *bag)
{
	bag->number_sign = 0;
	bag->zero = 0;
	bag->minus = 0;
	bag->plus = 0;
	bag->space = 0;
	bag->width = -1;
	bag->precision = -1;
	bag->length_modifier = "";
	bag->type = 0;
}
