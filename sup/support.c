/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:01:15 by mmarti            #+#    #+#             */
/*   Updated: 2019/08/22 17:01:17 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_envcpy(char **environ)
{
	int		i;
	int		c;
	char	**new;

	i = 0;
	c = ft_count_str(environ);
	if (!(new = (char **)ft_memalloc(sizeof(char *) * (c + 1))))
		return (0);
	if (!c)
		return (new);
	while (environ[i])
	{
		if (!(new[i] = ft_strdup(environ[i])))
		{
			free_tab(new, i);
			ft_error(0, ENOMEM, 0);
			return (0);
		}
		i++;
	}
	return (new);
}

void	free_tab(char **tab, int i)
{
	if (i < 0)
		return ;
	while (i >= 0)
		free(tab[i--]);
	free(tab);
}

int		ft_realloc(char **buf, size_t buff_size)
{
	char	*new_buf;
	int		len;

	len = ft_strlen(*buf);
	if (!(new_buf = (char *)ft_memalloc(len + buff_size + 1)))
	{
		ft_error(0, ENOMEM, 0);
		return (-1);
	}
	ft_memcpy(new_buf, *buf, len);
	*buf = new_buf;
	return (0);
}

char	*ft_pathjoin(char *s1, char *s2)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	if (!(str = (char *)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 2)))
		return (0);
	while (*s1)
		str[i++] = *s1++;
	if (*--s1 != '/')
		str[i++] = '/';
	while (*s2)
		str[i++] = *s2++;
	return (str);
}

char	*ft_getenv(char *str)
{
	size_t	len;
	char	*res;
	int		i;

	i = 0;
	res = 0;
	len = ft_strclen(str, '=');
	while (g_environ[i])
	{
		if (!(ft_strncmp(str, g_environ[i], ft_strclen(g_environ[i], '='))))
		{
			res = g_environ[i] + len + 1;
			break ;
		}
		i++;
	}
	return (res);
}
