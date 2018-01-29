/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 19:42:29 by lhernand          #+#    #+#             */
/*   Updated: 2018/01/27 19:44:26 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrev(char *str)
{
	int 	l;
	int 	i;
	char 	temp;

	l = ft_strlen(str) - 1;
	i = 0;
	while (i < (l - i))
	{
		temp = str[i];
		str[i] = str[l - i];
		str[l - i] = temp;
		i++;
	}
	return (str);
}
