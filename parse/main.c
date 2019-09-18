/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:16:21 by mmarti            #+#    #+#             */
/*   Updated: 2019/09/18 16:52:08 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
        {
			insert_ch(buf);
        }
		else if (buf == 27) {
			cur = key_mv(cur);
		}
		else if (buf == 127)
			delete_ch();
		else if (buf == '\n')
		{
			cur = new_line(command);
			//print_list(*command);
			return (1);
		}
		if (buf == 0)
			return (0);
		move_promt();
		tputs(tgetstr("cd", NULL), STDOUT_FILENO, ft_printnbr);
		write(STDOUT_FILENO, g_line.str, g_line.size);
		move_promt();
		move_back();
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
	/*ft_signal();
	g_environ = ft_envcpy(envp);*/
    orig_termios = enable_raw();
	init_edit();
	term_init();
	command = NULL;
	promt();
	while (ft_loop(&command)) {
        promt();
    }
	disable_raw(orig_termios);
	//free_tab(g_environ, ft_count_str(g_environ));
	return (0);
}

void	promt(void)
{
	write(STDOUT_FILENO, "$> ", 3);
}
