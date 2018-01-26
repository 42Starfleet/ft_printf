/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:24:43 by husui             #+#    #+#             */
/*   Updated: 2017/11/30 22:01:46 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *iter;

	iter = (unsigned char *)b;
	while (len)
	{
		*iter = (unsigned char)c;
		iter++;
		len--;
	}
	return (b);
}
