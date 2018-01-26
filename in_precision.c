#include "ft_printf.h"

bool	in_precision(char c)
{
	if (ft_isdigit(c))
		return (1);
	return (0);
}
