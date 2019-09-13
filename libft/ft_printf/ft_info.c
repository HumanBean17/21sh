/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:18:52 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/19 10:22:52 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_line(t_printf *list, va_list ap)
{
	char	*line;

	line = NULL;
	if (list->type == 'c')
		line = ft_putchar_2(va_arg(ap, unsigned));
	else if (list->type == 's')
		line = ft_strdup_n(va_arg(ap, char *), list->acc);
	else if (list->type == 'd' || list->type == 'i')
		line = ft_return_di(list, ap);
	else if (list->type == 'o')
		line = ft_return_o(list, ap);
	else if (list->type == 'u')
		line = ft_return_u(list, ap);
	else if (list->type == 'x' || list->type == 'X')
		line = ft_return_x(list, ap);
	else if (list->type == 'f' || list->type == 'F')
		line = ft_return_f(list, ap);
	else if (list->type == 'p')
		line = ft_put_address(va_arg(ap, unsigned long), list->acc);
	return (line);
}

int			ft_fill_info(const char *str, va_list ap)
{
	t_printf	*list;
	char		*field;
	char		*number;
	int			c;

	list = ft_printf_new();
	ft_fill(&list, str);
	number = ft_line(list, ap);
	field = ft_return_field(list, number);
	c = ft_printf_putstr(list->type, field, number);
	ft_do_del(&list, &number, &field);
	return (c);
}
