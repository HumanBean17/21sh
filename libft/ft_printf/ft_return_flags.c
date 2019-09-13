/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:59:56 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/19 11:02:43 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_width(t_printf *tmp, char *line)
{
	char	*width;
	char	c;

	width = NULL;
	if (tmp->width > 0)
	{
		if (tmp->acc == -1 && ft_flag_find(tmp->flag, '0') &&
		(!ft_flag_find(tmp->flag, '-')))
		{
			width = ft_strnew_n(tmp->width, '0');
			if ((line) && (line)[0] == '-')
			{
				c = line[0];
				line[0] = width[0];
				width[0] = c;
			}
		}
		else
			width = ft_strnew_n(tmp->width, ' ');
	}
	return (width);
}

char		*ft_tab(t_printf *tmp, char c)
{
	char *tab;

	tab = NULL;
	if (c != '-' && ft_flag_find(tmp->flag, ' ') &&
	(!ft_flag_find(tmp->flag, '+')) &&
		(tmp->type == 'i' || tmp->type == 'd'))
		tab = ft_strdup(" ");
	return (tab);
}

char		*ft_spec(t_printf *tmp)
{
	char *spec;

	spec = NULL;
	if (ft_flag_find(tmp->flag, '#') && (tmp->type == 'x' || tmp->type == 'X'))
		spec = ft_strdup("0x");
	if (ft_flag_find(tmp->flag, '#') && (tmp->type == 'o'))
		spec = ft_strdup("0");
	return (spec);
}

char		*ft_sign(t_printf *tmp, char s)
{
	char *sign;

	sign = NULL;
	if (ft_flag_find(tmp->flag, '+') && s != '-')
		sign = ft_strdup("+");
	return (sign);
}

char		*ft_return_field(t_printf *tmp, char *line)
{
	char	*width;
	char	*spec;
	char	*tab;
	char	*sign;

	tab = line ? ft_tab(tmp, line[0]) : ft_strdup("");
	spec = ft_spec(tmp);
	sign = line ? ft_sign(tmp, line[0]) : ft_strdup("");
	width = ft_width(tmp, line);
	ft_condition_spec(tmp, &line, &spec, width);
	ft_condition_sign(tmp, &line, &sign, width);
	ft_condition_tab(tmp, &line, &tab, width);
	ft_condition_width(tmp, &line, &width);
	ft_char_zero(&width, line, tmp);
	if (width)
	{
		ft_strdel(&line);
		return (width);
	}
	return (line);
}
