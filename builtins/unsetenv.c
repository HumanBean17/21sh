/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 21:32:10 by mmarti            #+#    #+#             */
/*   Updated: 2019/08/10 21:32:11 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shift_up(int i)
{
	while (g_environ[++i])
		g_environ[i - 1] = g_environ[i];
	free(g_environ[i]);
	g_environ[--i] = 0;
}

void	ft_delenv(char *com)
{
	int i;

	i = 0;
	while (g_environ[i] && ft_strncmp(com,
			g_environ[i], ft_strclen(g_environ[i], '=')))
		i++;
	if (g_environ[i])
	{
		free(g_environ[i]);
		g_environ[i] = 0;
		shift_up(i);
	}
}

void	ft_unsetenv(int ac, char **av)
{
	if (ac < 2)
		ft_error(*av, EFEWARGS, 0);
	else
	{
		while (*av)
		{
			ft_delenv(*av);
			av++;
		}
	}
}
