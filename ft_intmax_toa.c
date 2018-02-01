/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmax_toa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:04:08 by scamargo          #+#    #+#             */
/*   Updated: 2018/02/01 15:41:18 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include "ft_printf.h"

static int		num_len(intmax_t num)
{
	int len;
	
	len = 0;
	while ((num = num / 10))
		len++;
	return (len);
}

static void		set_intmax_toa(char **p_str, intmax_t num)
{
	if (num < 10)
	{
		**p_str = num + '0';
		(*p_str)++;
		return ;
	}
	set_intmax_toa(p_str, num / 10);
	set_intmax_toa(p_str, num % 10);	
}

char			*ft_intmax_toa(intmax_t num)
{
	int len;
	char	*str;
	char	*str_copy;
	len = num_len(num);
	len += (num < 0) ? 1 : 0;
	if(!(str = ft_memalloc(len + 1)))
		return (0);
	str_copy = str;
	if (num == INT64_MIN)
	{
		*str_copy++ = '-';
		*str_copy++ = '9';
		num = 223372036854775808;
	}
	else if (num < 0)
	{
		*str_copy++ = '-';
		num *= -1;
	}
	set_intmax_toa(&str_copy, num);
	*str_copy = '\0';
	return (str);
}

