/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 16:08:27 by scamargo          #+#    #+#             */
/*   Updated: 2018/02/01 16:35:56 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <inttypes.h>

static void		add_char_n_times(char c, int *p_n, int *p_i)
{
	while ((*p_n)-- > 0)
	{
		ft_putchar(c);
		(*p_i)++;
	}
}

static void		add_char_once(char c, int *p_i)
{
	ft_putchar(c);
	(*p_i)++;
}

void	print_d(t_bag *b, va_list args, int *i)
{
	char		*str;
	char		*str_orig;
	int			len;
	int			n;
	intmax_t	num;
	int			p;

	num = va_arg(args, intmax_t);
	if (!ft_strcmp(b->length_modifier, "l") || b->format_conversion == 'D' ||
	!ft_strcmp(b->length_modifier, "ll") || !ft_strcmp(b->length_modifier, "z"))
		num = (long)num;
	num = (ft_strlen(b->length_modifier) == 0) ? (int)num : num;
	num = (!ft_strcmp(b->length_modifier, "h")) ? (short)num : num;
	num = (!ft_strcmp(b->length_modifier, "hh")) ? (signed char)num : num;
	str = ft_intmax_toa(num);
	str_orig = str;
	len = ft_strlen(str);
	len -= (num < 0) ? 1 : 0;
	p = (b->precision - len > 0) ? b->precision - len : 0;
	len = (num == 0 && b->period && b->precision == 0) ? 0 : len;
	n = b->width - len - p;
	n -= (b->plus || b->space || num < 0) ? 1 : 0;
	if (!b->minus && (b->precision || !b->zero))
		add_char_n_times(' ', &n, i);
	if (num < 0)
	{
		add_char_once('-', i);
		str++;
	}
	else
	{
		if (b->plus)
			add_char_once('+', i);
		else if (b->space)
			add_char_once(' ', i);
	}
	if (b->precision)
		add_char_n_times('0', &p, i);
	else if (!b->minus && b->zero)
		add_char_n_times('0', &n, i);
	write(1, str, len);
	add_char_n_times(' ', &n, i);
	*i += len;
	free(str_orig);
}
