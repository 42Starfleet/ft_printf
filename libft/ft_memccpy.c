/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:58:35 by husui             #+#    #+#             */
/*   Updated: 2017/11/30 22:03:56 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
		size_t n)
{
	unsigned char *iter1;
	unsigned char *iter2;
	unsigned char character;

	iter1 = (unsigned char *)dst;
	iter2 = (unsigned char *)src;
	character = (unsigned char)c;
	while (n)
	{
		*iter1 = *iter2;
		if (*iter2 == character)
			return (++iter1);
		iter1++;
		iter2++;
		n--;
	}
	return (0);
}
