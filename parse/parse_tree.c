/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:27:47 by mmarti            #+#    #+#             */
/*   Updated: 2019/09/20 12:27:51 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		count_redirects(t_tree *tree)
{
	int red;

	red = 0;
	while (tree && tree->type != TEXEX)
	{
		red++;
		tree = tree->right;
	}
	return (red);
}

void	add_to_fdlist(int fd0, int fd1, int *tmp)
{
	while (*tmp >= 0)
		tmp++;
	tmp[0] = fd0;
	tmp[1] = fd1;
}

int	get_from_fdlist(int *fdlist)
{
	int i;
	int tmp;

	i = 0;
	if (fdlist[i] < 0)
		return (-1);
	while (fdlist[i] >= 0)
		i++;
	tmp = fdlist[--i];
	fdlist[i] = -1;
	return (tmp);
}

int *ft_fdmalloc(size_t size)
{
	int *res;

	if (!(res = (int *)malloc(sizeof(int) * size)))
		exit(123);
	while (size--)
		res[size] = -1;
	return (res);
}

int		*make_fdlist(int count)
{
	int fd[2];
	int *tmp;

	tmp = ft_fdmalloc(count * 2 + 1);
	while (count--)
	{
		pipe(fd);
		add_to_fdlist(fd[0], fd[1], tmp);
	}
	return (tmp);
}

void redirect(t_tree *tree, int *fdlist)
{
	if (!tree)
		return ;
	redirect(tree->left, fdlist);
	if (tree->type == TEXEX)
	{
		if (tree->parent->parent == 0 && tree->parent->right != tree)
			ft_do(tree->val, -1, get_from_fdlist(fdlist));
		else
			ft_do(tree->val, get_from_fdlist(fdlist), get_from_fdlist(fdlist));
	}
	redirect(tree->right, fdlist);
}

void	parse_tree(t_tree *tree)
{
	int *fdlist;

	if (!tree)
		return ;
	if (tree->type == TSEMICOL)
	{
		parse_tree(tree->left);
		parse_tree(tree->right);
	}
	else if (tree->type != TEXEX)
	{
		fdlist = make_fdlist(count_redirects(tree));
		redirect(tree, fdlist);
		waitpid(g_pid, 0, 0);
	}
}
