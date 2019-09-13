#include "minishell.h"

void	enable_raw(void)
{
	struct termios raw_tty;

	tcgetattr(STDIN_FILENO, &raw_tty);
	g_tty = raw_tty;
	raw_tty.c_lflag &= ~(ECHO);
	raw_tty.c_cc[VMIN] = 1;
	raw_tty.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw_tty);
}