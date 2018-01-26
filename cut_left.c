#include "ft_printf.h"

char		*cut_left(char *str, int n)
{
	int		i;
	int		length;
	char	*new;

	length = ft_strlen(str);
	if (n >= length)
		return ("");
	new = ft_strnew(length - n);
	while (n--)
		str++;
	i = 0;
	while (*str)
		new[i++] = *str++;
	return (new);
}
