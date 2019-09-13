/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:15:12 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/18 21:15:37 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_len(const char c)
{
	if (c == 'h' || c == 'l' || c == 'L')
		return (1);
	return (0);
}

int		ft_len_check(const char c[])
{
	if (c[0] == 'l' || c[1] == 'l')
		return (1);
	else if (c[0] == 'L' || c[1] == 'L')
		return (2);
	return (0);
}

int		ft_check_zero(const char *line)
{
	int i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

void	ft_char_zero(char **width, const char *line, t_printf *tmp)
{
	if (tmp->type == 'c' && (*width) && line && line[0] == '\0')
		(*width)[ft_strlen(*width) - 1] = '\0';
}
