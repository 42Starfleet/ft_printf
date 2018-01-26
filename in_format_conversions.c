#include "ft_printf.h"

bool	in_format_conversions(char c)
{
	char *all_format_conversions;

	all_format_conversions = "sSpdDioOuUxXcC%";
	while (*all_format_conversions)
	{
		if (c == *all_format_conversions)
			return (1);
		all_format_conversions++;
	}
	return (0);
}
