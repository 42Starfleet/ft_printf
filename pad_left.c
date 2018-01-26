/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 09:43:05 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/26 09:43:06 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*pad_left(char *str, int n, char c)
{
	int		i;
	int		length;
	char	*new;

	length = ft_strlen(str);
	if (length >= n)
		return (str);
	new = ft_strnew(n);
	i = 0;
	while (i < (n - length))
		new[i++] = c;
	while (i < n)
		new[i++] = *str++;
	return (new);
}
