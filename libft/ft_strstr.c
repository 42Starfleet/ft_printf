/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:24:25 by husui             #+#    #+#             */
/*   Updated: 2017/11/29 22:25:05 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int temp;

	i = 0;
	if (!(*little))
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		temp = i;
		while (little[j])
		{
			if (little[j] != big[temp])
				break ;
			temp++;
			j++;
		}
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
