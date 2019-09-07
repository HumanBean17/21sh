#include "minishell.h"

void	set_attr(void)
{
	struct termios new_termios_p;

	tcgetattr(STDIN_FILENO, &new_termios_p);
	g_save_tty = new_termios_p;
	new_termios_p.c_lflag &= ~(ECHO|ICANON);
	tcsetattr(STDIN_FILENO, TCSANOW, &new_termios_p);
}