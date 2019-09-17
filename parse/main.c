/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:16:21 by mmarti            #+#    #+#             */
/*   Updated: 2019/09/17 14:17:32 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int ft_loop()
{
	char    buf;

	init_edit();
    term_init();
    //tputs(tgetstr("im", NULL), STDOUT_FILENO, ft_printnbr);
	while (1)
	{
		buf = '\0';
		read(STDIN_FILENO, &buf, 1);
		if (ft_isprint(buf))
        {
            insert_ch(buf);
            //write(STDOUT_FILENO, g_line.str, g_line.size);
			write(STDOUT_FILENO, &buf, 1);
			//tputs(tgetstr("IC", NULL), STDOUT_FILENO, ft_printnbr);
        }
		else if (buf == 27)
		    key_mv();
		else if (buf == 127)
			delete();
		else if (buf == '\n')
		{
            new_line();
			return (1);
		}
		if (buf == '\0')
			return (0);
		/*if (g_line.x > 0)
            k_move();*/
	}

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
