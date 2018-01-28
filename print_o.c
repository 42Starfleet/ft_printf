#include "ft_printf.h"

void	print_o(t_bag *bag, va_list args, int *i)
{
	/*
		Most work with unsigned and decimals only

		// tmp variable for the original decimal value
		unsigned long tmp_var;
		// Have the decimal and a counter that will store our arguments
		unsigned long value;
		int len;
		-> While the bag->format_conversion is 'o' or 'O' && string is not '\0'
			1) Transform value to octal
				a) Use the tmp variable to store the remainder of the result from the decimal (decimal % 8)
				b) Divide your tmp to 8 (tmp /= 8)
			2) Increment your iteration
		-> Result with *i and tmp
	*/
}
