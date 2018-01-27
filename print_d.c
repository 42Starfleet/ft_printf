#include "ft_printf.h"

void	print_d(t_bag *bag, va_list args, int *i)
{
	char	*str;
	int		len;
	
	str = ft_itoa(va_arg(args, long));
	len = ft_strlen(str);
	// increase count by number of characters printed
	// if precision not given, and zero flag on
	if (!bag->precision && bag->zero)
	{
		// TODO: add zeroes based on width
	}	
	write(1, str, len);
	*i += len;
}
