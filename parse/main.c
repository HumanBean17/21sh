/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:16:21 by mmarti            #+#    #+#             */
/*   Updated: 2019/10/11 13:56:45 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int ft_loop(t_command **command)
{
	char				buf;
	static t_command 	*cur;

	if (!(*command))
		cur = NULL;
	while (1)
	{
		buf = '\0';
		read(STDIN_FILENO, &buf, 1);
		if (ft_isprint(buf))
			insert_ch(buf);
		if (buf == 1)
			home();
		else if (buf == 2)
			prev_word();
		else if (buf == 5)
			end();
		else if (buf == 6)
			next_word();
		else if (buf == 27)
			cur = key_mv(cur);
		else if (buf == 127)
			delete_ch();
		else if (buf == '\n')
		{
			write(STDOUT_FILENO, "\n", 1);
			g_quote = quote_find(g_line.str);
			if (!g_quote || !(g_quote % 2))
			{
				//ft_do(g_line.str);
				cur = new_line(command);
				return (1);
			}
			else
			{
				nl_join();
				g_line.fix = g_line.x;
			}
		}
		if (buf == 0)
			return (0);
		g_line.x = g_line.size;
        del_print();
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
    struct 	termios orig_termios;
    t_command		*command;

	if (argc > 1)
		return (0);
	(void)argv;
	ft_signal();
	g_quote = 0;
	g_environ = ft_envcpy(envp);
    orig_termios = enable_raw();
	init_edit();
	term_init();
	command = NULL;
	promt();
	while (ft_loop(&command))
		promt();
	disable_raw(orig_termios);
	free_tab(g_environ, ft_count_str(g_environ));
	return (0);
}
