/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_t_bag_variables.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 02:37:54 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/31 02:52:00 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_t_bag_variables(t_bag *bag)
{
	g_is_print_p = 0;
	bag->number_sign = 0;
	bag->zero = 0;
	bag->minus = 0;
	bag->plus = 0;
	bag->space = 0;
	bag->period = 0;
	bag->width = 0;
	bag->precision = 0;
	bag->length_modifier = "";
	bag->format_conversion = 0;
}
