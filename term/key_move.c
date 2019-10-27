#include "shell.h"

/*
** Ctrl + A bring the cursor to the beginning of the line.
** Ctrl + E bring the cursor to the end of the line.
** Ctrl + F bring jump forward to the next word.
** Ctrl + B bring jump back to the previous word.
*/

void		end(void)
{
	while (g_line.x < g_line.size)
	{
		tputs(tgetstr("nd", NULL), STDOUT_FILENO, ft_printnbr);
		g_line.x++;
	}
}

void		prev_word(void)
{
	int i;

	i = g_line.x - 1;
	while (g_line.x > 0 && (g_line.str[i] == '\t' || g_line.str[i] == ' '))
	{
		tputs(tgetstr("le", NULL), STDOUT_FILENO, ft_printnbr);
		g_line.x--;
		i--;
	}
	while (g_line.x > 0 && (g_line.str[i] != '\t' && g_line.str[i] != ' '))
	{
		tputs(tgetstr("le", NULL), STDOUT_FILENO, ft_printnbr);
		g_line.x--;
		i--;
	}
}

void		next_word(void)
{
	int i;

	i = g_line.x;
	while (g_line.x < g_line.size && (g_line.str[i] != '\t' && g_line.str[i] != ' '))
	{
		tputs(tgetstr("nd", NULL), STDOUT_FILENO, ft_printnbr);
		g_line.x++;
		i++;
	}
	while (g_line.x < g_line.size && (g_line.str[i] == '\t' || g_line.str[i] == ' '))
	{
		tputs(tgetstr("nd", NULL), STDOUT_FILENO, ft_printnbr);
		g_line.x++;
		i++;
	}
}

void		home(void)
{
    move_promt();
	g_line.x = 0;
}

t_command   *new_line(t_command **command)
{
	t_command *tmp;

	tmp = push_front(command, g_line.str);
	//check_list(*command);
	ft_strdel(&g_line.str);
	g_line.size = 0;
	g_line.x = 0;
	g_line.y = 0;
	g_line.lst = 0;
	g_line.fix = 0;
	return (tmp);
}

t_command *pick_up(t_command *cur, t_command **command)
{
	if (!cur->prev)
    	cur = new_line(command);
	if (cur->next)
		cur = cur->next;
	while (cur->next && ft_strequ(cur->str, ""))
		cur = cur->next;
    ft_strdel(&g_line.str);
    g_line.str = ft_strdup(cur->str);
    g_line.size = ft_strlen(g_line.str);
    g_line.x = 0;//g_line.size;
    //if (cur->next)
    //	return (cur->next);
	return (cur);
}

t_command   *pick_down(t_command *cur)
{
    t_command *tmp;

    tmp = cur->prev ? cur->prev : cur;
    while (tmp->prev && ft_strequ(tmp->str, ""))
    	tmp = tmp->prev;
    ft_strdel(&g_line.str);
    g_line.str = ft_strdup(tmp->str);
    g_line.size = ft_strlen(g_line.str);
    g_line.x = 0;//g_line.size;
    return (tmp);
}

t_command *key_mv(t_command *cur, t_command **command)
{
	char 		key_1;
	char 		key_2;
	t_command   *ret;

	read(STDIN_FILENO, &key_1, 1);
	read(STDIN_FILENO, &key_2, 1);
	if (key_1 == 91)
	{
		if (key_2 == 68 && g_line.x > 0 &&
		g_line.str[g_line.x - 1] != '\n') // LEFT
			g_line.x--;
		else if (key_2 == 67 && g_line.x < g_line.size) // RIGHT
			g_line.x++;
		else if (key_2 == 65) { // UP
			ret = pick_up(cur, command);
			/*if (ret != cur)
			{
				//sleep(2);
                move_promt();
                tputs(tgetstr("dl", NULL), STDOUT_FILENO, ft_printnbr);
                promt();
                //sleep(2);
				write(STDOUT_FILENO, g_line.str, g_line.size);
                //sleep(2);
				move_promt();
			}*/
            //printf("%s\n", ret->str);
			//sleep(3);
			return ret;
		}
		else if (key_2 == 66) { // DOWN
			ret = pick_down(cur);
			/*if (ret != cur)
			{
                //sleep(2);
                move_promt();
                tputs(tgetstr("dl", NULL), STDOUT_FILENO, ft_printnbr);
                promt();
                //sleep(2);
                write(STDOUT_FILENO, g_line.str, g_line.size);
                //sleep(2);
                move_promt();
			}*/
			return ret;
		}
	}
	return (cur);
}