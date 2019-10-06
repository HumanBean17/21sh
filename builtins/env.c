/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:41:58 by mmarti            #+#    #+#             */
/*   Updated: 2019/08/05 17:41:59 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_checkfl(char *com, int *i, int *u)
{
	int ind;

	ind = -1;
	while (com[++ind])
	{
		if (com[ind] == '-')
			continue ;
		if (com[ind] == 'i')
		{
			*i = 1;
			*u = 0;
		}
		else if (com[ind] == 'u')
		{
			*u = 1;
			*i = 0;
		}
		else
		{
			ft_putstr_fd("env: illegal option -- ", STDERR_FILENO);
			ft_putchar_fd(com[ind], STDERR_FILENO);
			return (env_err());
		}
	}
	return (0);
}

int		ft_setenvfl(char **com, int *i, int *u)
{
	int j;

	j = 0;
	*i = 0;
	*u = 0;
	while (com[j] && com[j][0] == '-')
	{
		if (ft_checkfl(com[j], i, u) < 0)
			return (-1);
		j++;
	}
	return (++j);
}

void	env_uns(char **com)
{
	if (!*com)
	{
		ft_putstr_fd("env: option requires an argument -- u", STDERR_FILENO);
		env_err();
		return ;
	}
	else if (ft_strchr(*com, '='))
	{
		ft_putstr_fd("env: unsetenv ", STDERR_FILENO);
		ft_putstr_fd(*com, STDERR_FILENO);
		ft_putstr_fd(": Invalid argument\n", STDERR_FILENO);
		return ;
	}
	else
		ft_delenv(*com);
}

void	ft_env(int ac, char **com)
{
	t_envfl	fl;
	int		j;
	char	**envcpy;

	fl.save_environ = g_environ;
	if (ac < 2)
		return (put_all_env());
	j = ft_setenvfl(&com[1], &fl.i, &fl.u);
	if (j < 0)
		return ;
	if (fl.i)
		envcpy = tmp_env_list(ft_count_str(&com[j]), &com[j], &j);
	else
		envcpy = empty_cpy();
	g_environ = envcpy;
	if (fl.u)
		env_uns(&com[j++]);
	if (com[j])
		check_built(&com[j]);
	free_tab(g_environ, ft_count_str(g_environ));
	g_environ = fl.save_environ;
}
