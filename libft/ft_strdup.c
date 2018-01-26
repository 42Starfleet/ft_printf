/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:20:48 by husui             #+#    #+#             */
/*   Updated: 2017/12/02 10:15:52 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	size;
	char			*str;

	size = 0;
	while (s1[size++])
		;
	str = (char*)malloc(sizeof(char) * size);
	if (!str)
		return (0);
	size = 0;
	while (s1[size])
	{
		str[size] = s1[size];
		size++;
	}
	str[size] = '\0';
	return (str);
}
