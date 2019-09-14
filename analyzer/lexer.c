#include "minishell.h"
#include <stdio.h>

int		isop(char c)
{
	if (c == ';' || c == '|' || c == '(' || c == ')' || c == '>')
		return (1);
	else
		return (0);
}

char	*skip_token(char *s)
{
	if (isop(*s))
	{
		while (*s && isop(*s))
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
	i = 0;
	while (str[i] && !(isop(str[i])))
		i++;
	if (!i)
		i++;
	if (isop(str[i + 1]) > 0)
		i++;
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