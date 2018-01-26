#include "ft_printf.h"

bool	in_length_modifiers(char **length_modifiers, char *length_modifier)
{
	while (*length_modifiers)
	{
		if (ft_strstr(*length_modifiers, length_modifier))
			return (1);
		length_modifiers++;
	}
	return (0);
}
