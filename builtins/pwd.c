/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 17:44:20 by mmarti            #+#    #+#             */
/*   Updated: 2019/10/11 11:24:59 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		check_args(char **arg, int *p)
{
	int	i;

	i = 0;
	if (!arg[1])
		return (0);
	while (arg[1][++i])
	{
		if (arg[1][i] == 'P')
			*p = 1;
		if (arg[1][i] == 'L')
			*p = 0;
		else
		{
			ft_putstr_fd("pwd: bad option: -", STDERR_FILENO);
			ft_putchar_fd(arg[1][i], STDERR_FILENO);
		}
	}
	return (0);
}

void	ft_putdir(int ac, char **arg)
{
	char	*dir;
	int		p;

	if (ac > 2)
	{
		ft_error(arg[0], EMANYARGS, 0);
		return ;
	}
	p = 0;
	dir = 0;
	if (check_args(arg, &p) < 0)
		return ;
	if (!p)
		dir = ft_strdup(ft_getenv("PWD"));
	if (!dir)
		dir = getcwd(0, PATH_MAX);
	ft_putstr_fd(dir, STDOUT_FILENO);
	free(dir);
	write(1, "\n", 1);
}
