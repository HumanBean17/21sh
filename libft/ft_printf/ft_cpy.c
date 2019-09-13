/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <lcrawn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:04:32 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/18 21:18:25 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			*ft_int_cpy(const int *a)
{
	int		len;
	int		*b;
	int		i;

	i = 1;
	len = a[0] + 1;
	b = ft_new_malloc(len);
	b[0] = a[0];
	while (i < len)
	{
		b[i] = a[i];
		i++;
	}
	return (b);
}

char		*ft_strcpy_end(char *destination, const char *source)
{
	int end_d;
	int end_s;

	if (!destination || !source)
		return (destination);
	end_d = ft_strlen(destination) - 1;
	end_s = ft_strlen(source) - 1;
	while (end_s >= 0 && end_d >= 0)
	{
		destination[end_d] = source[end_s];
		end_d--;
		end_s--;
	}
	return (destination);
}

char		*ft_strcpy_n(char *destination, const char *source)
{
	int i;

	if (!destination || !source)
		return (destination);
	i = 0;
	while (source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	return (destination);
}

char		*ft_strcpy(char *destination, const char *source)
{
	int i;

	if (!destination || !source)
		return (destination);
	i = 0;
	while (source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = source[i];
	return (destination);
}
