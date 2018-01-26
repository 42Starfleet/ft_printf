/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:15:39 by husui             #+#    #+#             */
/*   Updated: 2017/11/30 21:26:02 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*pointer;
	int		i;

	pointer = (void *)malloc(size);
	i = 0;
	if (!pointer)
		return (NULL);
	while (i != (int)size)
	{
		*(int *)(&pointer[i]) = 0;
		i++;
	}
	return (pointer);
}
