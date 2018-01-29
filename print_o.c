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

	// unsigned long	tmp;
	// unsigned long	len;
	//
	// while (bag->format_conversion == 'o' || bag->format_conversion == 'O')
	// {
	// 	tmp =
	// }
}

int		main()
{
	int	number;

	number = -1;
	printf("PRINTF OCTAL w/ 'o': %o\n", number);
	printf("PRINTF OCTAL w/ 'O': %O\n", number);
	// ft_printf("FT_PRINTF OCTAL w/ 'o': %o\n", number);
	// ft_printf("FT_PRINTF OCTAL w/ 'O': %O\n", number);
}
