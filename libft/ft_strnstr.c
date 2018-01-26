/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:32:24 by husui             #+#    #+#             */
/*   Updated: 2017/12/04 11:04:19 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int i;
	int j;
	int temp_i;
	int temp_len;

	i = -1;
	if (!(*little))
		return ((char *)big);
	while (big[++i] && len)
	{
		j = 0;
		temp_i = i;
		temp_len = len;
		while (little[j] && len--)
		{
			if (little[j] != big[temp_i++])
				break ;
			j++;
		}
		len = temp_len;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		len--;
	}
	return (0);
}
