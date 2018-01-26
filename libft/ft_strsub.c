/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 10:34:43 by husui             #+#    #+#             */
/*   Updated: 2017/12/01 19:23:49 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		s_length;
	int		i;

	if (s == NULL)
		return (NULL);
	s_length = ft_strlen((char *)s);
	new = ft_strnew(len);
	i = 0;
	if (new == NULL)
		return (NULL);
	while (s[start] && len)
	{
		new[i] = s[start];
		i++;
		start++;
		len--;
	}
	return (new);
}
