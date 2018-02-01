/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_cmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 08:24:57 by lilam             #+#    #+#             */
/*   Updated: 2018/01/31 02:37:56 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	number_cmp(char *str1, char *str2)
{
	char *cmp1;
	char *cmp2;

	cmp1 = ft_strdup(str1);
	truncate_zeros(&cmp1);
	cmp2 = ft_strdup(str2);
	truncate_zeros(&cmp2);
	if (cmp1[0] == '-' && (zeroed(cmp2) || ft_strcmp(cmp2, "0") > 0))
		return (-1);
	else if (cmp2[0] == '-' && (zeroed(cmp1) || ft_strcmp(cmp1, "0") > 0))
		return (1);
	if (cmp1[0] == '-' && cmp2[0] == '-')
	{
		if (ft_strlen(cmp2) > ft_strlen(cmp1))
			return (1);
		else if (ft_strlen(cmp1) > ft_strlen(cmp2))
			return (-1);
		return (-ft_strcmp(cmp1, cmp2));
	}
	if (ft_strcmp(cmp1, cmp2) > 0 && ft_strlen(cmp2) > ft_strlen(cmp1))
		return (-1);
	if (ft_strcmp(cmp1, cmp2) < 0 && ft_strlen(cmp2) < ft_strlen(cmp1))
		return (1);
	return (ft_strcmp(cmp1, cmp2));
}
