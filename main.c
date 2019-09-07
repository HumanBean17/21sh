/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:16:21 by mmarti            #+#    #+#             */
/*   Updated: 2019/09/07 14:29:26 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_loop(char *buf, size_t *buff_size)
{
	size_t	i;

	i = 0;
	while ((read(0, &buf[i], 1)) > 0 && buf[i] != '\n')
	{
		i++;
		if (i >= *buff_size - 1)
		{
			if (ft_realloc(&buf, *buff_size) < 0)
				exit(ENOMEM);
			*buff_size += *buff_size;
		}
	}
	if (buf[i] == '\n')
		buf[i] = 0;
	else
		write(1, "\n", 1);
	if (*buf)
	{
		ft_do(ft_strsplit(buf, ';'));
		ft_bzero(buf, ft_strlen(buf));
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*buf;
	size_t	buff_size;

	if (argc > 1)
		return (0);
	(void)argv;
	set_attr();
	ft_signal();
	g_environ = ft_envcpy(envp);
	buff_size = 256;
	if (!(buf = (char *)ft_memalloc(buff_size + 1)))
	{
		ft_error(0, ENOMEM, 0);
		return (0);
	}
	ft_putstr_fd("$> ", STDOUT_FILENO);
	while (ft_loop(buf, &buff_size) >= 0)
		ft_putstr_fd("$> ", STDOUT_FILENO);
	free_tab(g_environ, ft_count_str(g_environ));
	return (0);
}
