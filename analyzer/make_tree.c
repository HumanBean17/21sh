/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:27:00 by mmarti            #+#    #+#             */
/*   Updated: 2019/09/19 15:27:02 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_token	*find_min(t_token *token_list)
{
	t_type tmp;
	t_token *res;

	res = token_list;
	tmp = token_list->type;
	while (token_list)
	{
		if ((token_list->type % 100) < tmp % 100)
		{
			tmp = token_list->type;
			res = token_list;
		}
		token_list = token_list->next;
	}
	return (res);
}

void	rmtoken(t_token **token_list, t_token *todel)
{
	t_token *tmp;

	tmp = *token_list;
	if (count_tokens(*token_list) == 1)
	{
		free(*token_list);
		*token_list = 0;
		return ;
	}
	else
	{
		while (tmp->next != todel)
			tmp = tmp->next;
	}
	free(todel);
	tmp->next = 0;
}


t_tree	*make_tree(t_token *token_list)
{
	t_token *token_list_right;
	t_token *token_min;
	t_tree	*node;

	if (!token_list)
		return (0);
	token_min = find_min(token_list);
	node = new_tree_elem(token_min);
	token_list_right = token_min->next;
	rmtoken(&token_list, token_min);
	node->left = make_tree(token_list);
	node->right = make_tree(token_list_right);
	return (node);
}