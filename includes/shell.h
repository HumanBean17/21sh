/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:16:13 by mmarti            #+#    #+#             */
/*   Updated: 2019/10/27 14:42:29 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# define PATH_MAX 1024

# include "analyzer.h"
# include "libft.h"
# include "error.h"

# include <sys/wait.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <dirent.h>
# include <signal.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <stdio.h>

pid_t	g_pid;
char	**g_environ;
struct  s_line g_line;
int     g_quote;

typedef struct 	s_command
{
	char				*str;
	struct s_command 	*next;
	struct s_command	*prev;
}				t_command;


struct  s_line
{
    char            *str;
    size_t          size;
    int        		x;
    int 			y;
};

typedef struct	s_envfl
{
	int			i;
	int			u;
	char		**save_environ;
}				t_envfl;

/* edit line funcs */
int nl_index(const char *str, int limit);
void move_up(int limit);
void    check_list(t_command *command);
void move_right(int to_mv);
void move_del(void);
void    promt_join(void);
void move_left(int limit);
int nl_count(const char *str, int limit);
void move_do(void);
void nl_join(void);
char *cut_fix();
void	quote(void);
void    del_print();
void		home(void);
void		end(void);
int quote_find(const char *str);
void		next_word(void);
void		prev_word(void);
t_command * push_front(t_command **command, char *str);
void		print_list(t_command *command);
t_command	*new_command(char *str);
void	print_promt(void);
void move_promt();
char 	*char_str(char c);
void delete_ch(t_command *cur);
t_command *key_mv(t_command *cur, t_command **command);
int		ft_printnbr(int nbr);
void	term_init(void);
void 	move_back(void);
t_command * new_line(t_command **command);
int insert_ch(char buf);
struct termios		enable_raw(void);
void	            disable_raw(struct termios orig_termios);
void                init_edit();
void	ft_env(int ac, char **com);
void	        ft_manage_proc(t_tree *node, int fd1);
int             check_built(char **command);
char			*ft_pathjoin(char *s1, char *s2);
void			ft_cd(int ac, char **new_dir);
void			ft_echo(char **str);
void			ft_putdir(int ac, char **arg);
char			*ft_getenv(char *str);
void			ft_signal();
int				ft_realloc(char **buf, size_t add_to_buf);
void			ft_setenv(int ac, char **value);
void			ft_unsetenv(int ac, char **av);
void			ft_execute(t_tree *leaf, int fd1);
void			ft_delenv(char *com);
void			ft_env(int ac, char **com);
int				add_env(char *env, char *value);
void			ft_do(char *inp);
char			*search_bin(char *filename, char *path);
void			free_tab(char **ta, int i);
int				env_err();
char			**empty_cpy();
void			pwd_update(char *new_dir);
void			put_all_env(void);
char			**ft_envcpy(char **environ);
char			**tmp_env_list(int ac, char **com, int *j);
int				check_rights(char *fname);
void			pasteenv(char **com);

#endif
