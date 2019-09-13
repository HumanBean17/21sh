/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longarifm_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:28:47 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/18 21:31:00 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			*ft_shift_right(int **a)
{
	int i;
	int j;
	int len;
	int *b;

	i = 1;
	j = 1;
	len = (*a)[0] + 1;
	while ((*a)[i] == 0 && i < len)
		i++;
	if (i == 1)
		return (*a);
	b = ft_new_malloc((sizeof(int) * (len - i)));
	b[0] = len - i;
	while (i < len)
	{
		b[j] = (*a)[i];
		i++;
		j++;
	}
	ft_int_del(a);
	return (b);
}

char		*ft_convert_2(int *a, int sign)
{
	char	*s;
	int		i;
	int		j;
	int		len;

	s = ft_strnew(a[0] + sign);
	j = sign == 0 ? 0 : 1;
	s[0] = j == 1 ? '-' : (char)(a[1] + 48);
	i = ft_find_start(a);
	len = a[0] + 1;
	while (i < len)
	{
		s[j] = (char)(a[i] + 48);
		i++;
		j++;
	}
	ft_int_del(&a);
	return (s);
}

int			*ft_cast_2(unsigned long num, int len)
{
	int *pow;
	int *dec;
	int shift;
	int i;

	i = 0;
	shift = len - 63 < 0 ? 0 : len - 63;
	dec = ft_new_malloc(len + 2);
	dec[0] = len == 0 ? 1 : len;
	len = len > 63 ? 63 : len;
	while (len >= 0)
	{
		if (((num >> (unsigned long)i) & 1u) != 0)
		{
			pow = ft_long_pow(i + shift, 2);
			pow = ft_shift_right(&pow);
			ft_sum_2(&dec, pow);
			ft_int_del(&pow);
		}
		len--;
		i++;
	}
	return (dec);
}

void		ft_sum_2(int **sum, const int *b)
{
	int	size;
	int	i;
	int	start;

	size = b[0];
	i = size;
	start = (*sum)[0];
	while (i >= 1)
	{
		(*sum)[start] += b[i];
		start--;
		i--;
	}
	ft_move_2(sum);
}

void		ft_move_2(int **a)
{
	int	size;
	int	i;
	int	c;

	size = (*a)[0] + 1;
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
