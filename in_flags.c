#include "ft_printf.h"

bool	in_flags(t_bag *bag, char c)
{
	char	*all_possible_flags;

	if (bag->zero == 0)
		all_possible_flags = "#-+ 0";
	else
		all_possible_flags = "#-+ ";
	while (*all_possible_flags)
	{
		if (c == *all_possible_flags)
			return (1);
		all_possible_flags++;
	}
	return (0);
}
