/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:46:59 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/26 00:46:59 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(char *format, ...)
{
	va_list	arguments;
	int		number_of_printed_characters;

	number_of_printed_characters = 0;
	va_start(arguments, format);
	while (*format)
	{
		if (*format == '%')
			handle_percent(&format, arguments, &number_of_printed_characters);
		if (*format != '%')
		{
			ft_putchar(*format);
			number_of_printed_characters++;
		}
		format++;
	}
	va_end(arguments);
	return (number_of_printed_characters);
}
