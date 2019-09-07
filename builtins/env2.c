/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:22:20 by mmarti            #+#    #+#             */
/*   Updated: 2019/08/26 20:33:24 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_all_env(void)
{
	int i;

	i = 0;
	while (g_environ[i])
	{
		ft_putstr_fd(g_environ[i], STDOUT_FILENO);
		write(1, "\n", 1);
		i++;
	}
}

int		env_err(void)
{
	ft_putstr_fd("\nusage: env [-i] [[-u name] "\
	"[name=value ...] [utility [argument ...]]\n", STDERR_FILENO);
	return (-1);
}

char	**empty_cpy(void)
{
	char **envcpy;

	if (!(envcpy = (char **)ft_memalloc(sizeof(char *))))
	{
		ft_error(0, ENOMEM, 0);
		return (0);
	}
	return (envcpy);
}

char **tmp_env_list(int ac, char **com, int *j)
{
	char **tmp_env;
	int i;

	i = 0;
	if(!(tmp_env = (char **)ft_memalloc(sizeof(char *) * ac)))
	{
		ft_error(0, ENOMEM, 0);
		exit(0);
	}
	while (*com && (ft_strchr(*com, '=')))
	{
		if (com[i][0] == '=')
		{
			ft_error(0, ENOCOM, *com);
			free_tab(tmp_env, ft_count_str(tmp_env));
			return (0);
		}
		tmp_env[i++] = ft_strdup(*com++);
		(*j)++;
	}
	return (tmp_env);
}
