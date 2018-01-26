/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:33:30 by husui             #+#    #+#             */
/*   Updated: 2017/11/30 21:51:10 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	int		i;
	char	*new;

	i = 0;
	new = (char *)malloc(size + 1);
	if (new == NULL)
		return (NULL);
	while (i != (int)size)
	{
		new[i] = '\0';
		i++;
	}
	new[i] = '\0';
	return (new);
}
