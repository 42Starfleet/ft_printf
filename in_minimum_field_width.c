#include "ft_printf.h"

bool	in_minimum_field_width(char c)
{
	if (ft_isdigit(c))
		return (1);
	return (0);
}
