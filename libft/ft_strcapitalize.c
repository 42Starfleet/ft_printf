/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 08:29:16 by husui             #+#    #+#             */
/*   Updated: 2017/12/03 11:14:04 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	char	*beginning_of_string;
	int		should_capitalize;

	beginning_of_string = str;
	should_capitalize = 1;
	while (*str)
	{
		if ('a' <= *str && *str <= 'z' && should_capitalize)
			*str -= 32;
		else if ('A' <= *str && *str <= 'Z' && should_capitalize == 0)
			*str += 32;
		if (*str == ' ')
			should_capitalize = 1;
		else
			should_capitalize = 0;
		str++;
	}
	return (beginning_of_string);
}
