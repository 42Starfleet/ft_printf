/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztisnes <ztisnes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 23:39:43 by ztisnes           #+#    #+#             */
/*   Updated: 2018/01/28 23:53:04 by ztisnes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Converts integer to ascii. If the base is 10 and value is negative, then
** the resulting string is preceded with a minus sign '-'
*/

static int		len_nbr_base(int value, int base)
{
	int len;

	len = 0;
	while (value)
	{
		len += 1;
		value /= base;
	}
	return (len);
}

static char		*negative_sign(int n, int base, char *ptr)
{
	if (n < 0 && base == 10)
		ptr[0] = '-';
	return (ptr);
}

char			*ft_itoa_base(int n, int base)
{
	int		len;
	long	value;
	char	*ptr;
	char	*b;

	len = len_nbr_base(n, base);
	value = n;
	if (!(b = ft_strdup("0123456789ABCDEF")))
		return (NULL);
	if (value == 0)
		return (ft_strdup("0"));
	len += (value < 0 && base == 10) ? 1 : 0;
	value *= (value < 0) ? -1 : 1;
	if (!(ptr = ft_strnew(len)))
		return (NULL);
	while (value)
	{
		ptr[--len] = b[value % base];
		value /= base;
	}
	negative_sign(n, base, ptr);
	ft_strdel(&b);
	return (ptr);
}
