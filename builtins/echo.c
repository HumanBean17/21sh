/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:52:39 by mmarti            #+#    #+#             */
/*   Updated: 2019/10/11 11:24:59 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_echo(char **str)
{
    //write(STDOUT_FILENO, *str, ft_strlen(*str));
   // sleep(5);
	while (*str)
	{
		ft_putstr_fd(*str, STDOUT_FILENO);
		ft_putchar_fd(' ', STDOUT_FILENO);
		str++;
	}
	ft_putchar_fd('\n', STDOUT_FILENO);
}
