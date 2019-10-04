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
#include <errno.h>

//void	ft_fopen(char **fname, t_tree *node, int fd[])
//{
//	struct stat stbuf;
//
//	if (stat(*fname, &stbuf) == 0)
//	{
//		if (node->type == TGREAT) {
//			if ((fd[1] = open(*fname, O_RDWR | O_TRUNC)) < 0)
//				printf("%s", strerror(errno));
//		}
//		else
//			fd[1] = open(*fname, O_RDWR | O_APPEND);
//	}
//	else {
//		if ((fd[1] = open(*fname, O_CREAT | S_IRWXU | O_RDWR)) < 0)
//			printf("%s", strerror(errno));
//	}
//	fd[0] = -1;
//	node->left->type = TFILE;
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
	else
	{
		ft_manage(tree, -1);
		waitpid(-1, 0, 0);
	}
}
