/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:06:23 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/19 11:10:30 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_return_di(t_printf *list, va_list ap)
{
	char *line;

	line = NULL;
	if (ft_len_check_dioux(list->len) == 0)
		line = ft_putnbr(va_arg(ap, int), list->acc);
	else if (ft_len_check_dioux(list->len) == 1)
		line = ft_putnbr_short(va_arg(ap, int), list->acc);
	else if (ft_len_check_dioux(list->len) == 2)
		line = ft_putnbr_long(va_arg(ap, long int), list->acc);
	else if (ft_len_check_dioux(list->len) == 3)
		line = ft_putnbr_signed(va_arg(ap, int), list->acc);
	else if (ft_len_check_dioux(list->len) == 4)
		line = ft_putnbr_llong(va_arg(ap, long long int), list->acc);
	return (line);
}

char	*ft_return_o(t_printf *list, va_list ap)
{
	char *line;

	line = NULL;
	if (ft_len_check_dioux(list->len) == 0)
		line = ft_base(va_arg(ap, unsigned int), 8, list->acc);
	else if (ft_len_check_dioux(list->len) == 1)
		line = ft_base_short(va_arg(ap, unsigned int), 8, list->acc);
	else if (ft_len_check_dioux(list->len) == 2)
		line = ft_base_long(va_arg(ap, unsigned long int), 8, list->acc);
	else if (ft_len_check_dioux(list->len) == 3)
		line = ft_base_char(va_arg(ap, unsigned int), 8, list->acc);
	else if (ft_len_check_dioux(list->len) == 4)
		line = ft_base_llong(va_arg(ap, unsigned long long int), 8, list->acc);
	return (line);
}

char	*ft_return_u(t_printf *list, va_list ap)
{
	char *line;

	line = NULL;
	if (ft_len_check_dioux(list->len) == 0)
		line = ft_put_unsigned(va_arg(ap, unsigned int), list->acc);
	else if (ft_len_check_dioux(list->len) == 1)
		line = ft_put_unsigned_short(va_arg(ap, unsigned int), list->acc);
	else if (ft_len_check_dioux(list->len) == 2)
		line = ft_put_unsigned_long(va_arg(ap, unsigned long int), list->acc);
	else if (ft_len_check_dioux(list->len) == 3)
		line = ft_put_unsigned_char(va_arg(ap, unsigned int), list->acc);
	else if (ft_len_check_dioux(list->len) == 4)
		line = ft_put_unsigned_llong(va_arg(ap, unsigned long long int),
				list->acc);
	return (line);
}

char	*ft_return_x(t_printf *list, va_list ap)
{
	char *line;

	line = NULL;
	if (ft_len_check_dioux(list->len) == 0)
		line = ft_base(va_arg(ap, unsigned int), 16, list->acc);
	else if (ft_len_check_dioux(list->len) == 1)
		line = ft_base_short(va_arg(ap, unsigned int), 16, list->acc);
	else if (ft_len_check_dioux(list->len) == 2)
		line = ft_base_long(va_arg(ap, unsigned long int), 16, list->acc);
	else if (ft_len_check_dioux(list->len) == 3)
		line = ft_base_char(va_arg(ap, unsigned int), 16, list->acc);
	else if (ft_len_check_dioux(list->len) == 4)
		line = ft_base_llong(va_arg(ap, unsigned long long int), 16, list->acc);
	return (line);
}

char	*ft_return_f(t_printf *list, va_list ap)
{
	char *line;

	line = NULL;
	if (ft_len_check(list->len) == 2)
		line = ft_put_float(va_arg(ap, long double), list->acc);
	else
		line = ft_put_float(va_arg(ap, double), list->acc);
	return (line);
}
