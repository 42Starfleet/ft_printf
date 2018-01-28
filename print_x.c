/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 21:35:15 by lhernand          #+#    #+#             */
/*   Updated: 2018/01/28 01:20:37 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static	void	initialize(int *i, int *rem, int *len, int *num, char *str)
{
	*i = 0;
	*rem = 0;
	*num = 0;
	*len = ft_strlen(str);
}

static	char	*print_hex(char *str, int *l)
{
	int i;
	int rem;
	int len;
	int num;
	char *number;
	int a = 0;

	initialize(&i, &rem, &len, &num, str);
	number = ft_strnew(len + 1);
	while (a < len)
		number[a++] = '\0';
	num = ft_atoi(str);
	if (num == 0)
		number[i] = '\0';
	while (num > 0)
	{
		rem = num % 16;
		if (rem > 9)
			number[i++] = (rem - 10) + 97;
		else
			number[i++] = rem + 48;
		num = num / 16;
	}
	number[i] = '\0';
	ft_strrev(number);
	return (number);
}

void			print_x(t_bag *bag, va_list args, int *i)
{
	int len;
	char *str;
	char *res;
	
	str = ft_itoa(va_arg(args, long));
	len = ft_strlen(str);
	res = print_hex(str, &len);
	*i += len;
	write(1, res, len);
}
