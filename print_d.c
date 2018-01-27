#include "ft_printf.h"

void	print_d(t_bag *bag, va_list args, int *i)
{
	char	*str;
	int		len;
	int		n;
	
	str = ft_itoa(va_arg(args, long));
	len = ft_strlen(str);
	// increase count by number of characters printed
	// if precision not given, and zero flag on
	if (bag->precision == -1 && bag->zero)
	{
		// TODO: add zeroes based on width
		n = bag->width - len;
		while (n-- > 0)
		{
			ft_putchar('0');
		//	(*i)++;
		}
	}	
	write(1, str, len);
	*i += len;
}
