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
	if (cur->next)
		cur = cur->next;
	while (cur->next && ft_strequ(cur->str, ""))
		cur = cur->next;
    ft_strdel(&g_line.str);
    g_line.str = ft_strdup(cur->str);
    g_line.size = ft_strlen(g_line.str);
    g_line.x = 0;//g_line.size;
    g_quote = quote_find(g_line.str);
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
	g_quote = quote_find(g_line.str);
    return (tmp);
}

t_command *key_mv(t_command *cur, t_command **command)
{
	char 		key_1;
	char 		key_2;
	t_command   *ret;
	int 		y;

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
			if (!cur->prev)
				cur = new_line(command);
			g_quote = quote_find(cur->str);
			if ((g_quote || (g_quote % 2)))
			{
				y = nl_count(cur->str, ft_strlen(cur->str));
				move_up(y);
				move_del();
				//move_left((int)g_line.size - g_line.x);
			}
			ret = pick_up(cur, command);
			g_quote = quote_find(g_line.str);
			if (g_quote || g_quote % 2)
			{
				move_del();
				write(STDOUT_FILENO, g_line.str, g_line.size);
			}
			return ret;
		}
		else if (key_2 == 66) { // DOWN
			g_quote = quote_find(cur->str);
			if ((g_quote || (g_quote % 2)))
			{
				y = nl_count(cur->str, ft_strlen(cur->str));
				move_up(y);
				move_del();
				//move_left((int)g_line.size - g_line.x);
			}
			ret = pick_down(cur);
			g_quote = quote_find(g_line.str);
			if (g_quote || g_quote % 2)
			{
				move_del();
				write(STDOUT_FILENO, g_line.str, g_line.size);
			}
			return ret;
		}
	}
	return (cur);
}