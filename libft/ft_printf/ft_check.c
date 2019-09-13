/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:12:27 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/19 10:11:52 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_type_and(const char c)
{
	if (c != 'd' && c != 'i' && c != 'o' &&
		c != 'u' && c != 'x' && c != 'X' &&
		c != 'e' && c != 'E' && c != 'f' &&
		c != 'F' && c != 'g' && c != 'G' &&
		c != 'a' && c != 'A' && c != 'c' &&
		c != 's' && c != 'C' && c != 'S' &&
		c != 'p' && c != 'n' && c != '%')
		return (1);
	return (0);
}

int		ft_type_or(const char c)
{
	if (c == 'd' || c == 'i' || c == 'o' ||
		c == 'u' || c == 'x' || c == 'X' ||
		c == 'e' || c == 'E' || c == 'f' ||
		c == 'F' || c == 'g' || c == 'G' ||
		c == 'a' || c == 'A' || c == 'c' ||
		c == 's' || c == 'C' || c == 'S' ||
		c == 'p' || c == 'n' || c == '%')
		return (1);
	return (0);
}

int		ft_flag(const char c)
{
	if (c == '#' || c == '0' || c == '+' || c == '-' || c == ' ')
		return (1);
	return (0);
}

int		ft_len_check_dioux(const char *c)
{
	if (c[0] == 'h' && c[1] != 'h')
		return (1);
	else if (c[0] == 'l' && c[1] != 'l')
		return (2);
	else if (c[0] == 'h' && c[1] == 'h')
		return (3);
	else if (c[0] == 'l' && c[1] == 'l')
		return (4);
	return (0);
}
