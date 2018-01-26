/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 21:00:12 by husui             #+#    #+#             */
/*   Updated: 2017/12/04 08:57:21 by husui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	token_length(char *s, char delimiter)
{
	int i;

	i = 0;
	while (*s == delimiter && *s)
		s++;
	while (*s)
	{
		if (*s == delimiter)
			break ;
		i++;
		s++;
	}
	return (i);
}

static int	tokens(char *s, char delimiter)
{
	int	exchange_count;

	while (*s == delimiter)
		s++;
	if (!*s)
		return (0);
	exchange_count = 0;
	while (*s)
	{
		while (*s != delimiter && *s)
			s++;
		while (*s == delimiter && *s)
			s++;
		exchange_count++;
	}
	return (exchange_count);
}

static char	*fill_token(char *dst, char *src, char delimiter)
{
	int length;
	int i;

	length = token_length(src, delimiter);
	dst = ft_strnew(length);
	i = 0;
	while (*src == delimiter)
		src++;
	while (*src && *src != delimiter)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	return (dst);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**table;
	int		i;
	int		token_count;

	if (s == NULL)
		return (NULL);
	token_count = tokens((char *)s, c);
	table = (char **)malloc(sizeof(char *) * token_count + 1);
	if (table == NULL)
		return (NULL);
	table[token_count] = NULL;
	i = 0;
	while (*s == c)
		s++;
	while (token_count--)
	{
		table[i] = fill_token(table[i], (char *)s, c);
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
		i++;
	}
	return (table);
}
