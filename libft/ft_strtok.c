/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 13:35:46 by mmarti            #+#    #+#             */
/*   Updated: 2019/08/24 13:35:47 by mmarti           ###   ########.fr       */
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

static	int			ft_count_words(const char *s)
{
	int end_of_line;
	int end_of_word;

	while (*s)
	{
		if (*s == 0)
			return (0);
		end_of_line = (*s != ' ' && *s != '\t' && *s != '\n' && *(s + 1) == 0);
		end_of_word = (*s != ' ' && *s != '\t' && *s != '\n' &&
				(*(s + 1) == ' ' || *(s + 1) == '\t' || *(s + 1) == '\n'));
		if (end_of_line || end_of_word)
			return (1 + ft_count_words(++s));
		++s;
	}
	return (0);
}

static	size_t		ft_wordsize(char *s)
{
	int count;

	count = 0;
	if (*s == '"')
	{
		while (++*s && *s != '"')
			count++;
	}
	else
	{
		while (*s && *s != ' ' && *s != '\t' && *s != '\n' && *s != '"')
		{
			s++;
			count++;
		}
	}
	return (count);
}

static	char		*ft_word(char *s)
{
	char	*strnew;
	int		i;
	size_t	size;

	i = 0;
	size = ft_wordsize(s);
	if (!(strnew = (char *)ft_memalloc(size + 1)))
		return (0);
	while (size--)
		strnew[i++] = *s++;
	return (strnew);
}

char				**ft_strtok(char *s)
{
	char		**str;
	size_t		words;
	size_t		i;

	if (!s)
		return (0);
	i = 0;
	words = ft_count_words(s);
	if (!(str = (char **)ft_memalloc((words + 1) * sizeof(char *))))
		return (0);
	if (words == 0)
		return (str);
	while (i < words)
	{
		while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '"')
			s++;
		str[i] = ft_word(s);
		if (!str[i++])
			return (memfree(str, i));
		s += ft_wordsize(s) + 1;
	}
	str[words] = 0;
	return (str);
}
