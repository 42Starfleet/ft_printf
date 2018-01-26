/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:55:59 by husui             #+#    #+#             */
/*   Updated: 2017/12/03 11:15:45 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n, int count)
{
	if (n > 9)
		return (count_digits(n / 10, count + 1));
	return (count + 1);
}

static char	*allocate_memory(int n)
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

static char	*string_min(void)
{
	char	*str;

	str = ft_strnew(11);
	if (str == NULL)
		return (NULL);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	char	*iter;

	if (n == 0)
		return (string_zero());
	if (n == -2147483648)
		return (string_min());
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
