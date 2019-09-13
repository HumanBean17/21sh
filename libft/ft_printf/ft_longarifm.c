/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longarifm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:22:46 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/19 10:11:52 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_convert_1(int *a, int round)
{
	char	*s;
	int		i;
	int		j;
	int		len;

	s = ft_strnew(round + 1);
	j = 1;
	s[0] = '.';
	i = 1;
	len = a[0];
	while (i < len && i <= round)
	{
		s[j] = (char)(a[i] + 48);
		i++;
		j++;
	}
	ft_int_del(&a);
	return (s);
}

int				*ft_cast_1(unsigned long num, int round)
{
	int		*pow;
	int		*frac;
	int		i;

	i = 0;
	frac = ft_new_malloc(64 + round);
	frac[0] = 64 + round;
	while (i < 64 && num > 0)
	{
		if (((num >> (unsigned long)(64 - i)) & 1u) != 0)
		{
			if (i - 1 > 0)
			{
				pow = ft_long_pow(i - 1, 5);
				ft_sum_1(&frac, pow);
				ft_int_del(&pow);
			}
		}
		i++;
	}
	return (frac);
}

void			ft_sum_1(int **sum, const int *b)
{
	int			size;
	int			i;

	i = 1;
	size = b[0];
	while (i <= size)
	{
		(*sum)[i] += b[i];
		i++;
	}
	ft_move_1(sum);
}

void			ft_move_1(int **a)
{
	int		size;
	int		i;
	int		c;

	size = (*a)[0];
	i = 1;
	while (i < size)
	{
		if ((*a)[i] >= 10 && i != 1)
		{
			c = (*a)[i] / 10;
			(*a)[i - 1] += c;
			(*a)[i] %= 10;
			i = 1;
		}
		i++;
	}
}
