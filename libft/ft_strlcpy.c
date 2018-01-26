/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 08:35:21 by husui             #+#    #+#             */
/*   Updated: 2017/12/03 09:01:16 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int overflow;

	if (!dest || !src)
		return (0);
	i = 0;
	j = 0;
	if (size > 0)
	{
		while (src[j] && i < size - 1)
			dest[i++] = src[j++];
		dest[i] = '\0';
	}
	overflow = 0;
	while (src[j++] != 0)
		overflow++;
	return (i + overflow);
}
