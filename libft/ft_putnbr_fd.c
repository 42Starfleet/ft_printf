/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 23:46:53 by husui             #+#    #+#             */
/*   Updated: 2017/12/03 11:12:22 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_helper_fd(int n, int fd)
{
	if (n > 9)
	{
		ft_putnbr_helper_fd(n / 10, fd);
		ft_putnbr_helper_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(214748364, fd);
		ft_putnbr_fd(8, fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	ft_putnbr_helper_fd(n, fd);
}
