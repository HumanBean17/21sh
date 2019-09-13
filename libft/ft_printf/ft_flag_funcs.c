/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:51:59 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/19 11:52:16 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_flags		*ft_flag_create(const char c)
{
	t_flags *tmp;

	tmp = NULL;
	tmp = (t_flags *)malloc(sizeof(t_flags));
	if (tmp)
	{
		tmp->flag = c;
		tmp->flag_next = NULL;
	}
	return (tmp);
}

int			ft_flag_find(t_flags *alst, const char c)
{
	t_flags *tmp;

	tmp = alst;
	while (tmp)
	{
		if (tmp->flag == c)
			return (tmp->flag);
		tmp = tmp->flag_next;
	}
	return (0);
}

void		ft_flag_push(t_flags **elem, const char c)
{
	t_flags *tmp;

	tmp = *elem;
	while (tmp->flag_next)
		tmp = tmp->flag_next;
	tmp->flag_next = ft_flag_create(c);
}

void		ft_flag_new(t_printf **elem, const char c)
{
	if (!(*elem)->flag)
	{
		(*elem)->flag = ft_flag_create(c);
		return ;
	}
	ft_flag_push(&(*elem)->flag, c);
}
