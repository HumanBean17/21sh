/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:23:34 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/19 11:42:30 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

char	*ft_putnbr(int n, int round)
{
	int		num;
	int		i;
	char	*c;
	char	*result;

	if (round == 0 && n == 0)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	c = ft_strnew(21);
	i = 0;
	c[0] = n == 0 ? '0' : c[0];
	if (n < 0)
	{
		c[ft_n_len(n)] = '-';
		n *= -1;
	}
	num = (int)n;
	while (num > 0)
	{
		c[i++] = (char)(num % 10 + 48);
		num /= 10;
	}
	result = ft_round_dioux(&c, round);
	return (result);
}
