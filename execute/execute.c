/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:09:45 by mmarti            #+#    #+#             */
/*   Updated: 2019/08/22 17:09:47 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*locate(char *fname, char **path)
{
	DIR				*dr;
	struct dirent	*dirent;

	if (!path)
		return (fname);
	while (*path)
	{
		if (!(dr = opendir(*path)))
		{
			path++;
			continue;
		}
		while ((dirent = readdir(dr)))
		{
			if (!(ft_strcmp(dirent->d_name, fname)))
			{
				closedir(dr);
				return (ft_pathjoin(*path, dirent->d_name));
			}
		}
		closedir(dr);
		path++;
	}
	return (ft_strdup(fname));
}

char	*search_bin(char *filename, char *path)
{
	char	**paths;
	char	*res;

	if (!path)
		return (ft_strdup(filename));
	if (!(paths = ft_strsplit(path, ':')))
		return (0);
	if (!(res = locate(filename, paths)))
		return (0);
	free_tab(paths, ft_count_str(paths));
	return (res);
}

int		check_rights(char *fname)
{
	struct stat stbuf;

	if (lstat(fname, &stbuf) < 0)
		return (0);
	else
	{
		if ((stbuf.st_mode & S_IXUSR) == 0)
			return (-1);
	}
	return (0);
}

void	ft_execute(char **com)
{
	char *fname;

	fname = search_bin(com[0], ft_getenv("PATH"));
	g_pid = fork();
	if (!g_pid)
	{
		if (execve(fname, com, g_environ) < 0)
		{
			if (check_rights(fname) < 0)
				ft_error(0, EPERM, fname);
			else
				ft_error(0, ENOCOM, *com);
			exit(0);
		}
	}
	else
		g_pid = wait(&g_pid);
	free(fname);
}
