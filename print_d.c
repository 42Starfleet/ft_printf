#include "ft_printf.h"
#include <stdio.h>
#include <inttypes.h>

void	print_d(t_bag *bag, va_list args, int *i)
{
	char		*str;
	int			len;
	int			n;
	intmax_t	num;

	num = va_arg(args, intmax_t);
	if (ft_strlen(bag->length_modifier) == 0)
		num = (int)num;
	else if (!ft_strcmp(bag->length_modifier, "h"))
		num = (short)num;
	else if (!ft_strcmp(bag->length_modifier, "hh"))
		num = (signed char)num;
	else if (!ft_strcmp(bag->length_modifier, "l"))
		num = (long)num;
	else if (!ft_strcmp(bag->length_modifier, "ll") || 
			ft_strcmp(bag->length_modifier, "z"))
		num = (long long)num;
	str = ft_intmax_toa(num); 
	len = ft_strlen(str);
	n = bag->width - len;
	if (!bag->minus && (bag->precision || !bag->zero))
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
		len--;
		(*i)++;
	}
	else
	{
		if (bag->plus)
		{
			ft_putchar('+');
			(*i)++;
			n--;
		}
		else if (bag->space)
		{
			ft_putchar(' ');
			(*i)++;
		}
	}
	// increase count by number of characters printed
	// if precision not given, and zero flag on
	if (!bag-> minus && !bag->precision && bag->zero)
	{
		// TODO: add zeroes based on width
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
	// TODO: see why you cant free str
}
