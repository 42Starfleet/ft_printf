#include "ft_printf.h"

void	print_d(t_bag *bag, va_list args, int *i)
{
	char	*str;
	int		len;
	// increase count by number of characters printed
	str = ft_itoa(va_arg(args, long));
	len = ft_strlen(str);
	write(1, str, len);
	*i += len;
}
