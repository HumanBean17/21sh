/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:14:03 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/19 11:45:11 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_new_malloc(size_t size)
{
	int *ar;
	int i;

	ar = NULL;
	if (size <= 0)
		return (ar);
	i = 0;
	ar = (int *)malloc(sizeof(int) * size);
	while (i < (int)size)
	{
		ar[i] = 0;
		i++;
	}
	return (ar);
}
