#include "ft_printf.h"

int			ft_printf(char *format, ...)
{
	va_list	arguments;
	int		number_of_printed_characters;
	int i;

	i = 0;
	number_of_printed_characters = 0;
	va_start(arguments, format);
	while (*format)
	{
		if (*format == '%')
			handle_percent(&format, arguments, &number_of_printed_characters);
		else if (*format != '%')
		{
			ft_putchar(*format);
			number_of_printed_characters++;
			format++;
		}
	}
	va_end(arguments);
	return (number_of_printed_characters);
}
