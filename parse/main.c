/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:16:21 by mmarti            #+#    #+#             */
/*   Updated: 2019/09/14 11:16:50 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <ctype.h>

static int ft_loop()
{
	char 			buf;

	while (1)
	{
		buf = '\0';
		read(STDIN_FILENO, &buf, 1);
        edit_refresh();
		/*if (ft_isprint(buf) && buf != 27)
		{
            //write(STDOUT_FILENO, &buf, 1);
            //append_edit(&buf, 1);

            //write(STDOUT_FILENO, g_E.row->chars, g_E.row->size);
        }*/
		if (buf == '\n')
		{
			write(1, "\n", 1);
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
    struct 	termios orig_termios;

	if (argc > 1)
		return (0);
	(void)argv;
	//ft_signal();
	//g_environ = ft_envcpy(envp);
    orig_termios = enable_raw();
    init_edit();
    open_edit();
	ft_putstr_fd("$> ", STDOUT_FILENO);
	while (ft_loop()) {
        ft_putstr_fd("$> ", STDOUT_FILENO);
    }
	disable_raw(orig_termios);
	free_tab(g_environ, ft_count_str(g_environ));
	return (0);
}
