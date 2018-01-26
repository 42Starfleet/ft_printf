/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_right.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 09:43:15 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/26 09:43:16 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*cut_right(char *str, int n)
{
	int		i;
	int		length;
	char	*new;

	length = ft_strlen(str);
	if (n >= length)
		return ("");
	new = ft_strnew(length - n);
	i = 0;
	while (i < (length - n))
		new[i++] = *str++;
	return (new);
}
