/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 21:31:09 by mmarti            #+#    #+#             */
/*   Updated: 2019/08/09 21:31:11 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_replace_env(char *env, char *value)
{
	int		i;
	char	*old_val;

	i = 0;
	old_val = ft_getenv(env);
	if (ft_strlen(value) <= ft_strlen(old_val))
	{
		ft_bzero(old_val, ft_strlen(old_val));
		ft_memcpy(old_val, value, ft_strlen(value));
		return (0);
	}
	else
	{
		if (ft_realloc(&env, ft_strlen(value) + 2) < 0)
			return (0);
		env[ft_strlen(env)] = '=';
		ft_strcat(env, value);
	}
	while (ft_strncmp(g_environ[i], env, ft_strclen(g_environ[i], '=')))
		i++;
	free(g_environ[i]);
	g_environ[i] = env;
	return (0);
}

char	**new_envlist(void)
{
	char	**new;
	int		i;

	i = -1;
	if (!(new = (char **)ft_memalloc(sizeof(char *) *
			(ft_count_str(g_environ) + 2))))
		return (0);
	while (g_environ[++i])
		new[i] = ft_strdup(g_environ[i]);
	return (new);
}

int		add_env(char *env, char *value)
{
	char **new_environ;
	char *new_env;

	if (ft_getenv(env))
		return (ft_replace_env(env, value));
	if (!(new_environ = new_envlist()))
		return (-1);
	if (!(new_env = (char *)ft_memalloc(ft_strlen(env) + ft_strlen(value) + 2)))
		return (-1);
	ft_memcpy(new_env, env, ft_strlen(env));
	new_env[ft_strlen(env)] = '=';
	if (value)
		ft_memcpy(&new_env[ft_strlen(env) + 1], value, ft_strlen(value));
	new_environ[ft_count_str(g_environ)] = new_env;
	free_tab(g_environ, ft_count_str(g_environ));
	g_environ = new_environ;
	return (0);
}

void	ft_setenv(int ac, char **av)
{
	if (ac < 2)
		put_all_env();
	else if (ac > 3)
		ft_error(av[0], EMANYARGS, 0);
	else
		add_env(av[1], av[2]);
}
