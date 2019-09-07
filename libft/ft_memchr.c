/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:04:48 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/05 19:04:50 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*ar;
	unsigned char	ch;

	ch = (unsigned char)c;
	ar = (unsigned char *)arr;
	while (n--)
	{
		if (*ar == ch)
			return (void *)(ar);
		ar++;
	}
	return (0);
}
