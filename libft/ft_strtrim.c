/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:35:31 by husui             #+#    #+#             */
/*   Updated: 2017/12/04 09:45:36 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	this_string_has_only_whitespaces_or_none(char *s)
{
	while (*s)
	{
		if (!(*s == ' ' || *s == '\n' || *s == '\t'))
			return (0);
		s++;
	}
	return (1);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*new;

	if (s == NULL)
		return (NULL);
	if (this_string_has_only_whitespaces_or_none((char *)s))
		return (ft_strcpy(malloc(sizeof(char) * 2), ""));
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = 0;
	while (!(this_string_has_only_whitespaces_or_none((char *)&s[j])))
		j++;
	new = ft_strnew(j - i);
	if (new == NULL)
		return (NULL);
	k = 0;
	while (i < j)
	{
		new[k++] = s[i];
		i++;
	}
	return (new);
}
