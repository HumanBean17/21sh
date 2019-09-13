/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_adress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:16:24 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/19 10:37:14 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_put_address(unsigned long s, int round)
{
	char *base;
	char *prec;
	char *x;
	char *result;

	base = ft_base_long(s, 16, 0);
	if (round - (int)ft_strlen(base) < 0)
		prec = ft_strdup("");
	else
		prec = ft_strnew_n(round - ft_strlen(base), '0');
	x = ft_strjoin("0x", prec);
	ft_strdel(&prec);
	if (base)
		result = ft_strjoin(x, base);
	else if (round == -1)
		return (ft_strdup("0x0"));
	else
		return (x);
	ft_strdel(&base);
	ft_strdel(&x);
	return (result);
}
