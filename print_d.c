/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 16:08:27 by scamargo          #+#    #+#             */
/*   Updated: 2018/02/01 16:22:48 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <inttypes.h>

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
	{
		while (n-- > 0)
		{
			ft_putchar(' ');
			(*i)++;
		}
	}
	if (num < 0)
	{
		ft_putchar('-');
		str++;
		(*i)++;
	}
	else
	{
		if (b->plus)
		{
			ft_putchar('+');
			(*i)++;
		}
		else if (b->space)
		{
			ft_putchar(' ');
			(*i)++;
		}
	}
	if (b->precision)
	{
		while (p-- > 0)
		{
			ft_putchar('0');
			(*i)++;
		}
	}
	else if (!b->minus && b->zero)
	{
		while (n-- > 0)
		{
			ft_putchar('0');
			(*i)++;
		}
	}
	write(1, str, len);
	while (n-- > 0)
	{
		ft_putchar(' ');
		(*i)++;
	}
	*i += len;
	free(str_orig);
}
