#include "ft_printf.h"

long		power_l(long number, int exponent)
{
	long	result;

	result = 1;
	if (exponent == 0)
		return (result);
	while (exponent--)
		result = result * number;
	return (result);
}
