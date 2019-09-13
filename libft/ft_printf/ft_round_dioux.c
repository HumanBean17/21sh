/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_dioux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:33:50 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/19 11:34:17 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_round_dioux(char **num, int round)
{
	char	*r;
	char	*result;
	int		len;
	int		flag;

	len = ft_strlen(*num);
	flag = 0;
	ft_strrrev(*num, 0);
	if ((*num)[0] == '-')
	{
		flag = 1;
		round++;
	}
	r = round - len > 0 ? ft_strnew_n(round - len, '0') : ft_strnew(1);
	r[0] = flag == 1 && r[0] != '\0' ? '-' : r[0];
	(*num)[0] = round - len > 0 && flag == 1 ? '0' : (*num)[0];
	result = ft_strjoin(r, *num);
	ft_strdel(&r);
	ft_strdel(num);
	return (result);
}
