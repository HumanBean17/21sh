/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:05:09 by mmarti            #+#    #+#             */
/*   Updated: 2019/09/19 18:39:12 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *insert(char *s, char *envname, char *tmp)
{
	char *envval;
	char *res;

	envval = ft_getenv(envname);
	if (!(res = (char *)ft_memalloc(ft_strlen(s) + ft_strlen(envval) - ft_strlen(envname))))
	{
		ft_error(0, ENOMEM, 0);
		exit(ENOMEM);
	}
	*tmp = 0;
	ft_memcpy(res, s, ft_strlen(s));
	if (envval)
		ft_memcpy(&res[ft_strlen(res)],  envval, ft_strlen(envval));
	while (*tmp && *tmp != ' ' && *tmp != '\t')
		tmp++;
	ft_memcpy(&res[ft_strlen(res)], tmp, ft_strlen(tmp));
	free(s);
	free(envname);
	return (res);
}

char *insenv(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '~')
		{
			s = insert(s, ft_strdup("HOME"), &s[i]);
			i = 0;
		}
		else if (s[i] == '$')
		{
			s = insert(s, ft_strwdup(s + 1), &s[i]);
			i = 0;
		}
		i++;
	}
	return (s);
}

void pasteenv(char **com)
{
	while (*com)
	{
		*com = insenv(*com);
		com++;
	}
}

void	ft_parse(int ac, char **command)
{
	if (!(ft_strcmp("exit", command[0])))
		exit(0);
	else if (!(ft_strcmp("clear", command[0])))
		write(1, "\e[1;1H\e[2J", 11);
	else if (!(ft_strcmp("setenv", command[0])))
		ft_setenv(ac, command);
	else if (!(ft_strcmp("unsetenv", command[0])))
		ft_unsetenv(ac, command);
	else if (!(ft_strcmp("env", command[0])))
		ft_env(ac, command);
	else if (!(ft_strcmp("echo", command[0])))
		ft_echo(&command[1]);
	else if (!(ft_strcmp("pwd", command[0])))
		ft_putdir(ac, command);
	else if (!(ft_strcmp("cd", command[0])))
		ft_cd(ft_count_str(&command[1]), &command[1]);
	else
		ft_execute(command);
}

void	ft_do(char **inp)
{
	int		i;
	int		ac;
	char	**command;

	i = 0;
	while (inp[i])
	{
		command = ft_strtok(inp[i]);
		ac = ft_count_str(command);
		if (!*command)
		{
			free(command);
			i++;
			continue ;
		}
		pasteenv(command);
		ft_parse(ac, command);
		free_tab(command, ac);
		i++;
	}
	free_tab(inp, ft_count_str(inp));
}
