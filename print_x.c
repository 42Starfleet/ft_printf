/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 00:42:19 by lhernand          #+#    #+#             */
/*   Updated: 2018/01/29 00:42:32 by lhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static	void	initialize(int *i, int *rem, int *len, long *num, char *str)
{
	*i = 0;
	*rem = 0;
	*num = 0;
	*len = ft_strlen(str);
}

static	char	*print_hex(char *str, int *l, t_bag *bag, long test)
{
	int i;
	int rem;
	int len;
	long num;
	char *number;

	initialize(&i, &rem, &len, &num, str);
	number = ft_strnew(len);
//	num = ft_atoi(str);
	num = test;
	if (num == 0)
		number[i] = '\0';
	while (num > 0)
	{
		rem = num % 16;
		if (rem > 9)
		{
			if (bag->format_conversion == 'X')
				number[i++] = (rem - 10) + 65;
			else
				number[i++] = (rem - 10) + 97;
		}
		else
			number[i++] = rem + 48;
		num = num / 16;
	}
	ft_strrev(number);
	return (number);
}

void			print_x(t_bag *bag, va_list args, int *i)
{
	int len;
	char *str;
	char *res;
	char *new;
	long test;

	test = (unsigned long)va_arg(args, long);
//	str = ft_itoa(va_arg(args, long));
	printf("%d\n", test);
	str = ft_itoa(test);

	str = ft_itoa(va_arg(args, long));
	len = ft_strlen(str);
	printf("sting right here -> %s\n", str);
	res = print_hex(str, &len, bag, test);
	if (bag->number_sign)
	{
		if (bag->format_conversion == 'X')
			new = ft_strjoin("0X", res);
		else
			new = ft_strjoin("0x", res);
		len += 2;
	}
	else
		new = ft_strjoin("", res);
	*i += len - 1;
	ft_putstr(new);
	free(new);
}
