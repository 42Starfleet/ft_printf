/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 22:29:05 by husui             #+#    #+#             */
/*   Updated: 2017/12/02 01:41:01 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	unsigned int i;
	unsigned int j;
	unsigned int overflow;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	if (!dst[i] && size > 0)
	{
		while (src[j] && i < size - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	overflow = 0;
	while (src[j])
	{
		overflow++;
		j++;
	}
	return (i + overflow);
}
