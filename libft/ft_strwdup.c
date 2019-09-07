/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 20:25:19 by mmarti            #+#    #+#             */
/*   Updated: 2019/09/03 20:25:22 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strwdup(const char *str)
{
	int		len;
	char	*c;

	len = ft_strwlen(str);
	if (!(c = (char *)malloc(len * sizeof(*str) + 1)))
		return (0);
	while (*str)
		*c++ = *str++;
	*c = 0;
	return (c - len);
}

