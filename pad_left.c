#include "ft_printf.h"

char		*pad_left(char *str, int n, char c)
{
	int		i;
	int		length;
	char	*new;

	length = ft_strlen(str);
	if (length >= n)
		return (str);
	new = ft_strnew(n);
	i = 0;
	while (i < (n - length))
		new[i++] = c;
	while (i < n)
		new[i++] = *str++;
	return (new);
}
