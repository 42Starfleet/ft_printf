#include "ft_printf.h"

int		power_i(int number, int exponent)
{
	int	result;

	result = 1;
	if (exponent == 0)
		return (result);
	while (exponent--)
		result = result * number;
	return (result);
}
