/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 00:55:37 by mmarti            #+#    #+#             */
/*   Updated: 2019/08/26 20:29:31 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char		**memfree(char **fr, int i)
{
	while (--i >= 0)
	{
		free(fr[i]);
		fr[i] = 0;
	}
	free(fr);
	fr = 0;
	return (fr);
}

static	int			ft_count_words(const char *s, int c)
{
	int end_of_line;
	int end_of_word;

	while (*s)
	{
		if (*s == 0)
			return (0);
		end_of_line = (*s != c && *(s + 1) == 0);
		end_of_word = (*s != c && *(s + 1) == c);
		if (end_of_line || end_of_word)
			return (1 + ft_count_words(++s, c));
		++s;
	}
	return (0);
}

static	size_t		ft_wordsize(const char *s, int c)
{
	int count;

	count = 0;
	while (*s != c && *s != 0)
	{
		s++;
		count++;
	}
	return (count);
}

static	char		*ft_word(const char *s, int c)
{
	char	*strnew;
	int		i;
	size_t	size;

	i = 0;
	size = ft_wordsize(s, c);
	strnew = (char *)ft_memalloc(size + 1);
	if (!strnew)
		return (0);
	while (size != 0)
	{
		strnew[i++] = *s++;
		size--;
	}
	return (strnew);
}

char				**ft_strsplit(const char *s, int c)
{
	char		**str;
	size_t		words;
	size_t		i;

	if (!s)
		return (0);
	i = 0;
	words = ft_count_words(s, c);
	str = (char **)ft_memalloc((words + 1) * sizeof(char *));
	if (!str)
		return (0);
	if (*s == 0)
		return (str);
	while (i < words)
	{
		while (*s == c)
			s++;
		str[i] = ft_word(s, c);
		if (!str[i++])
			return (memfree(str, i));
		s += ft_wordsize(s, c) + 1;
	}
	str[words] = 0;
	return (str);
}
