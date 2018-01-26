/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 13:48:39 by husui             #+#    #+#             */
/*   Updated: 2017/11/30 22:03:14 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char character;

	character = (unsigned char)c;
	while (n--)
	{
		if (*(unsigned char *)s == character)
			return ((void *)s);
		s++;
	}
	return (0);
}
