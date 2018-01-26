/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_right.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 09:43:07 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/26 09:43:07 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*pad_right(char *str, int n, char c)
{
	int		i;
	int		length;
	char	*new;

	length = ft_strlen(str);
	if (length >= n)
		return (str);
	new = ft_strnew(n);
	i = 0;
	while (i < length)
		new[i++] = *str++;
	while (i < n)
		new[i++] = c;
	return (new);
}
