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

//int		count_redirects(t_tree *tree)
//{
//	int red;
//
//	red = 0;
//	while (tree && tree->type != TEXEX)
//	{
//		red++;
//		tree = tree->right;
//	}
//	return (red);
//}
//
//void	add_to_fdlist(int fd0, int fd1, int *tmp)
//{
//	while (*tmp >= 0)
//		tmp++;
//	tmp[0] = fd1;
//	tmp[1] = fd0;
//}
//
//int	get_from_fdlist(int *fdlist)
//{
//	static int i;
//
//	i++;
//	return (fdlist[i - 1]);
//}
//
//int *ft_fdmalloc(size_t size)
//{
//	int *res;
//
//	if (!(res = (int *)malloc(sizeof(int) * size)))
//		exit(123);
//	while (size--)
//		res[size] = -1;
//	return (res);
//}
//
//int		*make_fdlist(int count)
//{
//	int fd[2];
//	int *tmp;
//
//	tmp = ft_fdmalloc(count * 2 + 1);
//	while (count--)
//	{
//		pipe(fd);
//		add_to_fdlist(fd[0], fd[1], tmp);
//	}
//	return (tmp);
//}
//
//void redirect(t_tree *tree, int *fdlist)
//{
//	if (!tree)
//		return ;
//	redirect(tree->left, fdlist);
//	if (tree->type == TEXEX)
//	{
//		if (tree->parent->parent == 0 && tree->parent->right != tree)
//			ft_do(tree->val, -1, get_from_fdlist(fdlist));
//		else
//			ft_do(tree->val, get_from_fdlist(fdlist), get_from_fdlist(fdlist));
//	}
//	redirect(tree->right, fdlist);
//}


void	parse_tree(t_tree *tree)
{
	if (!tree)
		return ;
	if (tree->type == TSEMICOL)
	{
		parse_tree(tree->right);
		parse_tree(tree->left);
	}
	else if (tree->type == TEXEX)
	{
		if (check_built(tree->val) < 0)
		{
			g_pid = fork();
			if (!g_pid)
				ft_execute(tree, -1);
		}
	}
	else
		ft_manage_proc(tree, -1);
	waitpid(-1, 0, 0);
}
