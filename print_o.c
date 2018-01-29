#include "ft_printf.h"
# define INIT int i; int tmp; int len; long long oct; int a; char *number;
static char	 *print_octal(char *str, int *l)
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
		-> if there is a '-', then cast it to a unsigned integer
		-> Result with *i and tmp
	*/
	INIT;
	i = 0;
	tmp = 0;
	oct = 0;
	a = 0;
	len = ft_strlen(str);
	number = ft_strnew(len + 1);
	while (a < len)
		number[a++] = '\0';
	oct = ft_atoi(str);
	if (oct == 0)
		number[i] = '\0';
	while (oct > 0)
	{
		tmp = oct % 8;
		oct /= 8;
		number[i++] = tmp + '0';
	}
	number[i] = '\0';
	ft_strrev(number);
	return (number);
}

void		print_o(t_bag *bag, va_list args, int *i)
{
	int len;
	char *str;
	char *res;
	long input;

	input = va_arg(args, long);
	if (input < 0)
		input = (unsigned long)input;
	str = ft_itoa2(input);
	printf("TRYING TO PRINT 4294967286: %s\n", str);
	len = ft_strlen(str);
	res = print_octal(str, &len);
	*i += len;
	write(1, res, len);
}
