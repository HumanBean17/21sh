/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 12:17:19 by mmarti            #+#    #+#             */
/*   Updated: 2019/08/26 18:16:40 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	path_back(char *new_pwd)
{
	char *tmp;

	tmp = 0;
	while (*++new_pwd)
	{
		if (*new_pwd == '/')
			tmp = new_pwd;
	}
	if (tmp)
		ft_bzero(tmp, ft_strlen(tmp));
}

void	add_path(char *new_pwd, char *starpath)
{
	size_t len;

	len = ft_strlen(new_pwd);
	if (new_pwd[len - 1] != '/')
		new_pwd[len] = '/';
	ft_strcat(new_pwd, starpath);
}

char	*find_new_pwd(char **starpath)
{
	char *pwd;
	char *new_pwd;

	pwd = ft_getenv("PWD");
	if (!(new_pwd = (char *)ft_memalloc(PATH_MAX + 1)))
		return (0);
	ft_memcpy(new_pwd, pwd, ft_strlen(pwd));
	while (*starpath)
	{
		if (!(ft_strcmp(*starpath, "..")))
			path_back(new_pwd);
		else
			add_path(new_pwd, *starpath);
		starpath++;
	}
	return (new_pwd);
}

void	pwd_update(char *new_dir)
{
	char **starpath;
	char *new_pwd;

	starpath = ft_strsplit(new_dir, '/');
	if (*new_dir == '/')
		new_pwd = ft_strdup(new_dir);
	else if (!(ft_strcmp(new_dir, "-")))
		new_pwd = ft_strdup(ft_getenv("OLDPWD"));
	else
		new_pwd = find_new_pwd(starpath);
	add_env("OLDPWD", ft_getenv("PWD"));
	add_env("PWD", new_pwd);
	free(new_pwd);
	free_tab(starpath,ft_count_str(starpath));
}
