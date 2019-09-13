/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longarifm_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:31:46 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/18 21:31:48 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_mlt(const int *a, const int *b, int n)
{
	int *mlt;
	int i;
	int k;

	i = 1;
	mlt = ft_new_malloc(n);
	while (i < n)
	{
		k = i;
		while (k < n)
		{
			mlt[i] += a[i] * b[k];
			k++;
		}
		i++;
	}
	mlt[0] = n - 1;
	ft_move_2(&mlt);
	return (mlt);
}

void	ft_round(int **a, int **b, int round)
{
	if (round == 0)
	{
		if ((*b)[1] >= 5)
		{
			(*a)[(*a[0])]++;
			ft_move_2(a);
		}
		return ;
	}
	if ((*b)[round + 1] >= 5)
	{
		(*b)[round]++;
		ft_move_1(b);
	}
}

int		ft_find_start(const int *a)
{
	int i;
	int len;

	i = 1;
	len = a[0];
	while (i < len && a[i] == 0)
		i++;
	return (i);
}
