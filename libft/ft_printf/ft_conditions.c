/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:16:35 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/19 11:45:42 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_condition_sign(t_printf *tmp, char **line,
	char **sign, char *width)
{
	char *ptr;

	if ((!ft_flag_find(tmp->flag, '0') ||
	tmp->width < (int)ft_strlen(*line)) && tmp->type != 'u')
	{
		ptr = ft_strdup(*line);
		ft_strdel(line);
		*line = ft_strjoin(*sign, ptr);
		ft_strdel(&ptr);
	}
	else if (ft_flag_find(tmp->flag, '+') && tmp->type != 'u')
		ft_strcpy_n(width, *sign);
	ft_strdel(sign);
}

void		ft_condition_tab(t_printf *tmp, char **line,
	char **tab, char *width)
{
	char *ptr;

	if (!ft_flag_find(tmp->flag, '0'))
	{
		ptr = ft_strdup(*line);
		ft_strdel(line);
		*line = ft_strjoin(*tab, ptr);
		ft_strdel(&ptr);
	}
	else
		ft_strcpy_n(width, *tab);
	ft_strdel(tab);
}

void		ft_condition_width(t_printf *tmp, char **line, char **width)
{
	char *ptr;
	char *cur;

	if (tmp->type == '%')
	{
		ptr = ft_strdup(*line);
		cur = ft_strnew_n(1, tmp->type);
		ft_strdel(line);
		*line = ft_strjoin(ptr, cur);
		ft_strdel(&ptr);
		ft_strdel(&cur);
	}
	if (ft_flag_find(tmp->flag, '-'))
		ft_strcpy_n(*width, *line);
	else if (tmp->width >= (int)ft_strlen(*line))
		ft_strcpy_end(*width, *line);
	else
		ft_strdel(width);
}

void		ft_condition_spec(t_printf *tmp, char **line,
	char **spec, char *width)
{
	char *ptr;

	if (((!ft_flag_find(tmp->flag, '0') || ft_flag_find(tmp->flag, '-')) &&
		(ft_check_zero(*line) || (ft_strlen(*spec) == 1 && tmp->acc != -1))) &&
		(((int)ft_strlen(*line) != tmp->acc || !ft_check_zero(*line)) ||
		(tmp->type == 'x' || tmp->type == 'X')))
	{
		ptr = ft_strdup(*line);
		ft_strdel(line);
		*line = ft_strjoin(*spec, ptr);
		ft_strdel(&ptr);
	}
	else if (ft_check_zero(*line))
		ft_strcpy_n(width, *spec);
	ft_strdel(spec);
}
