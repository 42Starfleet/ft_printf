/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:49:52 by husui             #+#    #+#             */
/*   Updated: 2017/11/30 16:18:57 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *iter1;
	unsigned char *iter2;

	iter1 = (unsigned char *)s1;
	iter2 = (unsigned char *)s2;
	while (n--)
	{
		if (!(*iter1 == *iter2))
			return (*iter1 - *iter2);
		iter1++;
		iter2++;
	}
	return (0);
}
