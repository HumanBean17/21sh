/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:16:21 by mmarti            #+#    #+#             */
/*   Updated: 2019/09/13 12:16:36 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int ft_loop()
{
	char 	buf;
	size_t	i;

	i = 0;
	enable_raw();
	while ((read(0, &buf, 1)))
	{
		if (buf == '\n')
		{
			write(1, "\n", 1);
			return (1);
		}
		i++;
	}
	/*if (buf[i] == '\n')
		buf[i] = 0;
	else
		write(1, "\n", 1);
	if (*buf)
	{
		ft_do(ft_strsplit(buf, ';'));
		ft_bzero(buf, ft_strlen(buf));
	}*/
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc > 1)
		return (0);
	(void)argv;
	ft_signal();
	g_environ = ft_envcpy(envp);
	ft_putstr_fd("$> ", STDOUT_FILENO);
	while (ft_loop())
		ft_putstr_fd("$> ", STDOUT_FILENO);
	free_tab(g_environ, ft_count_str(g_environ));
	return (0);
}
