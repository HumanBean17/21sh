#include "minishell.h"

void	disable_raw(struct termios orig_termios)
{
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1)
		die("tcsetattr");
}

struct termios	enable_raw(void)
{
	struct termios raw_tty;
	struct termios orig_termios;

	if (tcgetattr(STDIN_FILENO, &raw_tty) == 1)
		die("tcgetattr");
	orig_termios = raw_tty;
	raw_tty.c_lflag &= ~(ECHO | ICANON);
	raw_tty.c_iflag &= ~(INPCK | IXON);
	raw_tty.c_cflag |= (CS8);
	raw_tty.c_cc[VMIN] = 1;
	raw_tty.c_cc[VTIME] = 0;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw_tty) == -1)
		die("tcsetattr");
	return (orig_termios);
}