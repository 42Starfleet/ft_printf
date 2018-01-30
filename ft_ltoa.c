/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:55:59 by husui             #+#    #+#             */
/*   Updated: 2018/01/29 14:35:21 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(long n, int count)
{
	if (n > 9)
		return (count_digits(n / 10, count + 1));
	return (count + 1);
}

static char	*allocate_memory(long n)
{
	char	*str;
	int		i;

	if (n < 0)
	{
		n = -n;
		str = ft_strnew(count_digits(n, 0) + 1);
		if (str == NULL)
			return (NULL);
		str[0] = '-';
		i = 1;
		while (i <= count_digits(n, 0))
			str[i++] = 'X';
	}
	else
	{
		str = ft_strnew(count_digits(n, 0));
		if (str == NULL)
			return (NULL);
		i = 0;
		while (i < count_digits(n, 0))
			str[i++] = 'X';
	}
	return (str);
}

static char	*string_zero(void)
{
	char	*str;

	str = ft_strnew(1);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	return (str);
}

char		*ft_ltoa(long n)
{
	char	*str;
	char	*iter;

	if (n == 0)
		return (string_zero());
	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	str = allocate_memory(n);
	if (str == NULL)
		return (NULL);
	iter = str;
	while (*iter)
		iter++;
	iter--;
	if (n < 0)
		n = -n;
	while (n)
	{
		*iter = (n % 10) + '0';
		n /= 10;
		iter--;
	}
	return (str);
}
