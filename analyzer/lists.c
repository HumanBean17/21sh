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
#include "../libft/libft.h"

t_token *get_last(t_token *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void get_token_type(t_token *token)
{
	if (token->type)
		return ;
	if (*token->val == '|')
		token->type = TPIPE;
	else if (*token->val == ';')
		token->type = TSEMICOL;
	else if (*token->val == '>')
	{
		token->next->type = TFILE;
		if (!(ft_strcmp(token->val, ">>")))
			token->type = TDGREAT;
		else
			token->type = TGREAT;
	}
	else
		token->type = TEXEX;
}

char	*ft_strtrim(char const *s)
{
	size_t st;
	size_t e;

	if (!s)
		return (0);
	st = 0;
	e = ft_strlen(s) - 1;
	while (s[st] == ' ' || s[st] == '\n' || s[st] == '\t')
		st++;
	if (s[st] == 0)
		return (0);
	while ((s[e] == ' ' || s[e] == '\n' || s[e] == '\t') && e > 0)
		e--;
	return (ft_strsub(s, st, e - st + 1));
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
	token->type = 0;
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
		exit(123);
	elem->parent = parent;
	elem->type = token->type;
	elem->val = ft_strtok(token->val);
	pasteenv(elem->val);
	elem->right = 0;
	elem->left = 0;
	return (elem);
}
