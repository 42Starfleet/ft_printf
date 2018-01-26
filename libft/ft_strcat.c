/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:19:41 by husui             #+#    #+#             */
/*   Updated: 2017/11/28 14:18:00 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	char *iter;

	iter = s1;
	while (*iter)
		iter++;
	while (*s2)
	{
		*iter = *s2;
		iter++;
		s2++;
	}
	*iter = '\0';
	return (s1);
}
