/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:16:54 by mmarti            #+#    #+#             */
/*   Updated: 2019/08/22 17:17:16 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int		ft_chdir(char *new_dir)
{
	if (!(ft_strcmp(new_dir, "-")))
		return (chdir(ft_getenv("OLDPWD")));
	else
		return (chdir(new_dir));
}

void	ft_cd(int ac, char **av)
{
	char *new_dir;

	if (ac == 0)
		new_dir = ft_getenv("HOME");
	else
		new_dir = av[0];
	if (ac > 1)
	{
		write(1, "cd: string not in pwd: ", 23);
		ft_putstr_fd(new_dir, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	else if (ft_chdir(new_dir) < 0)
	{
		ft_putstr_fd("cd: no such file or directory: ", STDERR_FILENO);
		ft_putstr_fd(new_dir, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	else
		pwd_update(new_dir);
}
