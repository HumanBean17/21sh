/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 07:32:10 by mmarti            #+#    #+#             */
/*   Updated: 2019/08/07 07:32:12 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_sigint(int sig)
{
	if (!g_pid)
	{
		write(1, "\n$> ", 4);
		return ;
	}
	kill(g_pid, sig);
	write(1, "\n", 1);
}

void	ft_signal(void)
{
	signal(SIGINT, &ft_sigint);
}
