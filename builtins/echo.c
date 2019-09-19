/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:52:39 by mmarti            #+#    #+#             */
/*   Updated: 2019/08/06 18:52:40 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_echo(char **str)
{
	while (*str)
	{
		ft_putstr_fd(*str, STDOUT_FILENO);
		ft_putchar_fd(' ', STDOUT_FILENO);
		str++;
	}
	ft_putchar_fd('\n', STDOUT_FILENO);
}
