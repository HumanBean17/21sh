/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_list_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:50:10 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/19 10:55:22 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_n_len(int num)
{
	int len;

	len = 0;
	if (num < 0)
		num *= -1;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

void		ft_do_del(t_printf **list, char **number, char **field)
{
	if ((*number) == (*field))
		ft_strdel(number);
	else
	{
		ft_strdel(field);
	}
	ft_printf_del(list);
}

void		ft_len_mod(t_printf **elem, const char *str, int i, int *c)
{
	if ((str[i] == 'h' || str[i] == 'l') &&
		str[i + 1] != 'h' && str[i + 1] != 'l')
	{
		(*elem)->len[*c] = str[i];
		*c += 10;
	}
	else
		(*elem)->len[*c] = str[i];
}

int			ft_fill(t_printf **elem, const char *str)
{
	int	i;
	int	c;

	i = 1;
	c = -1;
	while (str[i] != '\0' && ft_type_and(str[i]))
	{
		if (ft_flag(str[i]) && (*elem)->acc == -1)
			ft_flag_new(elem, str[i]);
		else if (ft_isdigit(str[i]) && (*elem)->acc == -1
		&& (*elem)->width == 0)
			i += ft_width_mod(elem, i, (char *)str);
		else if (str[i] == '.' && (*elem)->acc == -1)
		{
			(*elem)->acc = ft_atoi(str + i + 1);
			i += ft_n_len((*elem)->width) - 1;
		}
		else if (ft_len(str[i]) && ++c < 2)
			ft_len_mod(elem, str, i, &c);
		i++;
	}
	if (ft_type_or(str[i]))
		(*elem)->type = str[i];
	return (i);
}

t_printf	*ft_printf_new(void)
{
	t_printf *tmp;

	tmp = NULL;
	tmp = (t_printf *)malloc(sizeof(t_printf));
	if (tmp)
	{
		tmp->flag = NULL;
		tmp->width = 0;
		tmp->acc = -1;
		tmp->len[0] = 0;
		tmp->len[1] = 0;
		tmp->type = 0;
	}
	return (tmp);
}
