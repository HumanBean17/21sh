/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:07:02 by mmarti            #+#    #+#             */
/*   Updated: 2019/09/20 12:07:05 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <stdio.h>

int		isop(char c)
{
	if (c == ';' || c == '|' || c == '>')
		return (1);
	else
		return (0);
}

char	*skip_token(char *s)
{
	int max_op_len;

	max_op_len = 2;
	if (isop(*s))
	{
		while (isop(*s) && max_op_len--)
			s++;
	}
	else
	{
		while (*s && !(isop(*s)))
			s++;
	}
	return (s);
}

t_token *tokendup(char *str, t_token *lst)
{
	t_token *tmp;
	int i;

	tmp = get_last(lst);
	i = skip_token(str) - str;
	if (!tmp)
		lst = new_token(ft_strsub(str, 0, i));
	else
		tmp->next = new_token(ft_strsub(str, 0, i));
	return (lst);
}

t_token	*tokenize(char *inp)
{
	t_token *lst;

	lst = 0;
	if (!inp || !*inp)
		return (0);
	while (*inp)
	{
		lst = tokendup(inp, lst);
		inp = skip_token(inp);
	}
	return (lst);
}
