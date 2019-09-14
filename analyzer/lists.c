#include "minishell.h"

t_token *get_last(t_token *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

short get_token_type(char const *str)
{
	if (*str == '|')
		return (TPIPE);
	else if (*str == '(')
		return (TBRANCHOPEN);
	else if (*str == ';')
		return (TSEMICOL);
	else if (*str == ')')
		return (TBRANCHCLOSE);
	else if (*str == '>')
	{
		if (*str + 1 == '>')
			return (TREDIRECTX2);
		else
			return (TREDIRECT);
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
	if (!(token = (t_token *)ft_memalloc(sizeof(token))))
		exit(123);
	token->type = get_token_type(str);
	token->val = res;
	return (token);
}
