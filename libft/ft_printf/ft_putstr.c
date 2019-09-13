/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:23:46 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/19 11:43:01 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf_putstr(int type, char *field, const char *number)
{
	int c;

	c = 0;
	if (ft_toupper(type) == type)
		ft_putstr(ft_strupper(field));
	else
		ft_putstr(field);
	c = ft_strlen(field);
	if (type == 'c' && number && number[0] == '\0')
	{
		write(1, "\0", 1);
		c++;
	}
	return (c);
}

void	ft_putstr(char const *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}
