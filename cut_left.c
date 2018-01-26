/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 09:43:14 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/26 09:43:15 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*cut_left(char *str, int n)
{
	int		i;
	int		length;
	char	*new;

	length = ft_strlen(str);
	if (n >= length)
		return ("");
	new = ft_strnew(length - n);
	while (n--)
		str++;
	i = 0;
	while (*str)
		new[i++] = *str++;
	return (new);
}
