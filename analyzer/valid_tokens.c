#include "minishell.h"

static	int count_branches(t_token *lst)
{
	int count1;
	int count2;

	count1 = 0;
	count2 = 0;
	while (lst)
	{
		if (lst->type == TBRANCHOPEN)
			count1++;
		else if (lst->type == TBRANCHCLOSE)
			count2++;
		lst = lst->next;
	}
	if (count1 != count2)
	{
		count1 > count2 ? ft_error(0, EUNEXPTOKEN, "(") : ft_error(0, EUNEXPTOKEN, ")");
		return (-1);
	}
	return (0);
}

static	int check_branches(t_token *lst)
{
	if (count_branches(lst) < 0)
		return (-1);
	return (0);
	/*
	 * на случай,если понадобятся еще проверки
	 */
}

int valid_tokens(t_token *lst)
{
	if (!lst || !lst->type)
		return (-1);
	if (check_branches(lst) < 0)
		return (-1);
	if (lst->type != TEXEX)
	{
		ft_error(0, EUNEXPTOKEN, lst->val);
		return (-1);
	}
	while (lst)
	{
		if (lst->type != TEXEX)
			if (lst->next && lst->next->type != TEXEX)
			{
				ft_error(0, EUNEXPTOKEN, lst->next->val);
				return (-1);
			}
		lst = lst->next;
	}
	return (0);
}