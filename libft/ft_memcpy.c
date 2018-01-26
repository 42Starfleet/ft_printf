/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:49:40 by husui             #+#    #+#             */
/*   Updated: 2017/11/30 10:56:45 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char *iter1;
	unsigned char *iter2;

	iter1 = (unsigned char *)dst;
	iter2 = (unsigned char *)src;
	while (n)
	{
		*iter1 = *iter2;
		iter1++;
		iter2++;
		n--;
	}
	return (dst);
}
