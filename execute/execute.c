/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:09:45 by mmarti            #+#    #+#             */
/*   Updated: 2019/10/27 11:24:07 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*locate(char *fname, char **path)
{
	DIR				*dr;
	struct dirent	*dirent;
	char *res;

	if (!path)
		return (fname);
	while (*path)
	{
		if (!(dr = opendir(*path)))
		{
			path++;
			continue ;
		}
		while ((dirent = readdir(dr)))
		{
			if (!(ft_strcmp(dirent->d_name, fname)))
			{
				res = ft_pathjoin(*path, dirent->d_name);
				closedir(dr);
				return (res);
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
	return (access(fname, 1));
//	struct stat stbuf;
//
//	if (lstat(fname, &stbuf) < 0)
//		return (0);
//	else
//	{
//		if ((stbuf.st_mode & S_IXUSR) == 0)
//			return (-1);
//	}
//	return (0);
}

void	exec_pipe(t_tree *node, int fd1)
{
	int fd[2];

	g_pid = fork();
	if (!g_pid)
	{
		pipe(fd);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		if (fd1 >= 0)
		{
			dup2(fd1, STDOUT_FILENO);
			close(fd1);
		}
		ft_manage_proc(node->right, fd[1]);
		close(fd[1]);
		ft_execute(node->left, -1);
	}
}

int	ft_fopen(t_tree *node)
{
	struct stat stbuf;
	int fd;

	if (stat(node->left->val[0], &stbuf) == 0)
	{
		if (node->type == TGREAT) {
			if ((fd = open(node->left->val[0], O_RDWR | O_TRUNC)) < 0)
				ft_putstr_fd(strerror(errno), 2);
		}
		else
			if ((fd = open(node->left->val[0], O_RDWR | O_APPEND)) < 0)
				ft_putstr_fd(strerror(errno), 2);
	}
	else {
		if (node->type == TLESS)
		{
			ft_putstr_fd("No file", STDERR_FILENO);
			return (-1);
		}
		if ((fd = open(node->left->val[0], O_CREAT | S_IRWXU | O_RDWR)) < 0)
			ft_putstr_fd(strerror(errno), 2);
	}
	return(fd);
}

void	make_rdr(t_tree *node)
{
	int fd;
	int oldfd;

	//if (node->type == TLESS)
	//dup2(fd1, STDOUT_FILENO);
	if (node->type == TLESS)
	{
		oldfd = dup(STDIN_FILENO);
		fd = ft_fopen(node);
		dup2(fd, STDIN_FILENO);
		close(fd);
		ft_manage_proc(node->right, -1);
		dup2(oldfd, STDIN_FILENO);
		close(oldfd);
	}
	else
	{
		oldfd = dup(STDOUT_FILENO);
		fd = ft_fopen(node);
		ft_manage_proc(node->right, fd);
		dup2(oldfd, STDOUT_FILENO);
		close(oldfd);
	}

}


void	ft_manage_proc(t_tree *node, int fd1)
{
	if (node->type == TPIPE)
		exec_pipe(node, fd1);
	else if (node->type != TEXEX)
		make_rdr(node);
	else
	{
		g_pid = fork();
		if (!g_pid)
			ft_execute(node, fd1);
	}
}

void	ft_execute(t_tree *leaf, int fd1)
{
	char	*fname;

	fname = 0;
	if (fd1 >= 0)
	{
		dup2(fd1, STDOUT_FILENO);
		close(fd1);
	}
	if ((check_built(leaf->val)) == 0)
		exit(0);
	fname = search_bin(leaf->val[0], ft_getenv("PATH"));
	if (execve(fname, leaf->val, g_environ) < 0)
	{
		if (check_rights(fname) < 0)
			ft_error(0, EPERM, fname);
		else
			ft_error(0, ENOCOM, *leaf->val);
	}
	if (fname)
		free(fname);
}
