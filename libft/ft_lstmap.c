/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 07:57:39 by husui             #+#    #+#             */
/*   Updated: 2017/12/03 08:07:43 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;

	if (!lst)
		return (NULL);
	new = f(lst);
	if (lst->next)
	{
		new = ft_lstmap(lst->next, f);
		ft_lstadd(&new, f(lst));
	}
	return (new);
}
