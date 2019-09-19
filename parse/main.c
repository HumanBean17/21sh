/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:16:21 by mmarti            #+#    #+#             */
/*   Updated: 2019/09/19 20:14:47 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_loop(t_command **command, int f)
{
	int 				quote;
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
			quote = char_find(g_line.str, '\'');
			if (quote == 0 || quote % 2 == 0)
			{
				ft_do(ft_strsplit(g_line.str, ';'));
				cur = new_line(command);
				f = 1;
				return (f);
			}
			else
			{
				g_line.y++;
				g_line.fix = g_line.x;
				f = 2;
				return (f);
			}
		}
		if (buf == 0)
			return (0);
		del_print(f);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
    struct 	termios orig_termios;
    t_command		*command;
    int 			f;

	if (argc > 1)
		return (0);
	(void)argv;
	ft_signal();
	g_environ = ft_envcpy(envp);
    orig_termios = enable_raw();
	init_edit();
	term_init();
	command = NULL;
	promt();
	f = 1;
	while ((f = ft_loop(&command, f)))
	{
		if (f == 1)
			promt();
		else if (f == 2)
			quote();
	}
	disable_raw(orig_termios);
	free_tab(g_environ, ft_count_str(g_environ));
	return (0);
}
