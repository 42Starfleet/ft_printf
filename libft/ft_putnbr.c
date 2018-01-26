/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 23:13:42 by husui             #+#    #+#             */
/*   Updated: 2017/12/03 11:12:14 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_helper(int n)
{
	if (n > 9)
	{
		ft_putnbr_helper(n / 10);
		ft_putnbr_helper(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void		ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putnbr(214748364);
		ft_putnbr(8);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	ft_putnbr_helper(n);
}
