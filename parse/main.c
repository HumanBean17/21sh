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

int		ft_printnbr(int nbr)
{
    return (write(STDERR_FILENO, &nbr, 1));
}

static int ft_loop()
{
	char    buf;
	char    key_2;
	char    key_1;
	char    *clearstr;
	char    b[32];
	char    *ap = b;

	init_edit();
    tgetent(b, getenv("TERM"));
    clearstr = tgetstr("cl", &ap);
	while (1)
	{
		buf = '\0';
		read(STDIN_FILENO, &buf, 1);
		if (ft_isprint(buf))
        {
            insert_ch(buf);
        }
		else if (buf == 27)
        {
		    //write(STDOUT_FILENO, &buf, 1);
		    read(STDIN_FILENO, &key_1, 1);
            read(STDIN_FILENO, &key_2, 1);
            if (key_1 == 91)
            {
                if (key_2 == 68) // LEFT
                {
                    //write(STDOUT_FILENO, "left |", 5);
                    //write(STDOUT_FILENO, "\x001b[1D", 9);
                    g_line.x = ft_max(0, (int)g_line.x - 1);
                }
                else if (key_2 == 67) // RIGHT
                {
                    //write(STDOUT_FILENO, "right +", 6);
                    //write(STDOUT_FILENO, "\x001b[1C", 9);
                    g_line.x = ft_min(g_line.size, g_line.x + 1);
                }
            }
        }
		else if (buf == '\n')
		{
			write(1, "\n", 1);
            new_line();
			return (1);
		}
        //write(STDOUT_FILENO, "\x001b[1000D", 12);
		write(STDOUT_FILENO, &buf, 1);
        tputs(clearstr, STDOUT_FILENO, ft_printnbr);
        //write(STDOUT_FILENO, "\x001b[1000D", 12);
		if (g_line.x > 0)
            k_move();
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
