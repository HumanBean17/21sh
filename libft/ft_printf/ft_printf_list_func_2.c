/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_list_func_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:44:28 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/19 11:44:32 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_width_mod(t_printf **elem, int i, char *str)
{
	(*elem)->width = ft_atoi(str + i);
	return (ft_n_len((*elem)->width) - 1);
}
