/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:30:12 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/19 11:21:37 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew_n(size_t size, char c)
{
	char *str;

	str = NULL;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str)
	{
		ft_memset(str, c, size);
		str[size] = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_strnew(size_t size)
{
	char *str;

	str = NULL;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str)
	{
		ft_memset(str, '\0', size + 1);
		return (str);
	}
	return (NULL);
}
