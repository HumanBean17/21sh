/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:22:21 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/19 11:25:54 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_dec_initil(t_double *tmp)
{
	if (tmp->exp - 16383 < 0)
		return (ft_cast_2(0, 64));
	else if ((tmp->exp - 16383) < 64)
		return (ft_cast_2(tmp->man >>
		(unsigned long)(63 - ft_abs(tmp->exp - 16383)),
				ft_abs(tmp->exp - 16383)));
	else
		return (ft_cast_2(tmp->man, ft_abs(tmp->exp - 16383)));
}

int		*ft_fract_initil(t_double *tmp, int round)
{
	tmp->man = tmp->exp - 16383 < 0 ?
			tmp->man >> (unsigned long)(ft_abs(tmp->exp - 16383)) :
		tmp->man << (unsigned long)(ft_abs(tmp->exp - 16383));
	if (ft_abs(tmp->exp - 16383) >= 64)
		tmp->man = 0;
	return (ft_cast_1(tmp->man, round));
}

char	*ft_put_float_2(t_double *tmp, int round)
{
	int		*frac;
	int		*dec;
	char	*str_frac;
	char	*str_dec;
	char	*result;

	dec = ft_dec_initil(tmp);
	frac = ft_fract_initil(tmp, round);
	ft_round(&dec, &frac, round);
	str_frac = ft_convert_1(frac, round);
	str_dec = ft_convert_2(dec, tmp->sign);
	result = ft_strjoin(str_dec, str_frac);
	ft_strdel(&str_dec);
	ft_strdel(&str_frac);
	return (result);
}

char	*ft_put_float(long double num, int round)
{
	t_uprintf	*tmp;
	char		*str;

	tmp = (t_uprintf *)malloc(sizeof(t_uprintf));
	tmp->number = num;
	round = round == -1 ? 6 : round;
	str = ft_put_float_2(&(tmp->num), round);
	free(tmp);
	return (str);
}
