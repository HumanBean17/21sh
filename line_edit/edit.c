#include "minishell.h"

t_config	init_edit()
{
	t_config config;

	config.cx = 0;
	config.cy = 0;
	config.numrows = 0;
	return (config);
}

void	open_edit(t_config config)
{
	config.row.size = ft_strlen("Hello, world!");
	config.row.chars = ft_strdup("Hello, world!");
	config.numrows = 1;
}