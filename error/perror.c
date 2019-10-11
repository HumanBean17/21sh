/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 22:12:36 by mmarti            #+#    #+#             */
/*   Updated: 2019/10/11 11:24:59 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void			die(const char *s)
{
	perror(s);
	exit(1);
}

static	void	puterr(int code)
{
	static char *errors[6];

	errors[0] = "no memory to allocate";
	errors[1] = "permission denied";
	errors[2] = "no such file or directory";
	errors[3] = "command not found";
	errors[4] = "too few arguments";
	errors[5] = "too many arguments";
	if (code < 1 || code > 6)
		return ;
	ft_putstr_fd(errors[code - 1], STDERR_FILENO);
}

void			ft_error(char const *s1, int code, char const *s2)
{
	if (!s1)
		ft_putstr_fd("21sh: ", STDERR_FILENO);
	else
	{
		ft_putstr_fd(s1, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	puterr(code);
	if (s2)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(s2, STDERR_FILENO);
	}
	ft_putchar_fd('\n', STDERR_FILENO);
}