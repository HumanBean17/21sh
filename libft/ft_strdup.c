/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:46:05 by mmarti            #+#    #+#             */
/*   Updated: 2019/08/26 20:31:07 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		len;
	char	*c;

	if (!str)
		return (0);
	len = ft_strlen(str);
	if (!(c = (char *)malloc(len * sizeof(*str) + 1)))
		return (0);
	while (*str)
		*c++ = *str++;
	*c = 0;
	return (c - len);
}
