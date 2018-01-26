/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 08:46:14 by husui             #+#    #+#             */
/*   Updated: 2017/12/03 11:14:30 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	absolute(int value)
{
	if (value < 0)
		return (-value);
	else
		return (value);
}

int			*ft_range(int start, int end)
{
	int	*range;
	int	size;
	int	i;

	size = absolute(end - start) + 1;
	range = malloc(size);
	i = 0;
	if (start < end)
		while (start <= end)
		{
			range[i] = start;
			start++;
			i++;
		}
	else
		while (end <= start)
		{
			range[i] = start;
			start--;
			i++;
		}
	return (range);
}
