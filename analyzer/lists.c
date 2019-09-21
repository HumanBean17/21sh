/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:07:12 by mmarti            #+#    #+#             */
/*   Updated: 2019/09/20 12:07:13 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_token *get_last(t_token *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

short get_token_type(char const *str)
{
	if (*str == '|')
		return (TPIPE);
	else if (*str == ';')
		return (TSEMICOL);
	else if (*str == '>')
	{
		if (*str + 1 == '>')
			return (TDGREAT);
		else
			return (TGREAT);
	}
	else
		return (TEXEX);
}

t_token *new_token(char *str)
{
	t_token *token;
	char *res;

	if (!*str)
		return (0);
	res = ft_strtrim(str);
	if (!res)
		return (0);
	if (!(token = (t_token *)malloc(sizeof(t_token))))
		exit(123);
	token->type = get_token_type(str);
	token->val = res;
	token->next = 0;
	return (token);
}

size_t count_tokens(t_token *lst)
{
	size_t res;

	res = 0;
	while(lst)
	{
		res++;
		lst = lst->next;
	}
	return (res);
}

t_tree	*new_tree_elem(t_token *token, t_tree *parent)
{
	t_tree *elem;

	if (!(elem = (t_tree *)malloc(sizeof(t_tree))))
		return (0);
	if (parent)
		elem->parent = parent;
	else
		elem->parent = 0;
	elem->type = token->type;
	elem->val = token->val;
	elem->right = 0;
	elem->left = 0;
	return (elem);
}
