/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:16:13 by mmarti            #+#    #+#             */
/*   Updated: 2019/09/14 13:21:11 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define PATH_MAX 1024
# define ABUF_INIT {NULL, 0}

# include <stdlib.h>
# include "libft.h"
# include <string.h>
# include <unistd.h>
# include <sys/stat.h>
# include <dirent.h>
# include <signal.h>
# include "error.h"
# include <termios.h>
# include <wait.h>
# include <curses.h>
# include <term.h>

#include <stdio.h>

pid_t	g_pid;
char	**g_environ;
struct  s_editorConfig g_E;
struct  s_line g_line;

struct  s_line
{
    char            *str;
    size_t          size;
    int        x;
};

struct 	s_draw
{
    char *b;
    int len;
};

typedef struct  s_erow
{
	char 		*chars;
    int 		size;
}				t_erow;

struct 	s_editorConfig {
    int cx;
    int cy;
    int rowoff;
    int screenrows;
    int screencols;
    int numrows;
    t_erow *row;
    struct termios orig_termios;
};

typedef struct	s_envfl
{
	int			i;
	int			u;
	char		**save_environ;
}				t_envfl;

/* edit line funcs */
void    k_move();
void    new_line();
void    insert_ch(char buf);
void                edit_refresh(void);
void                append_edit(char *s, size_t len);
void                row_realloc(t_erow **tmp, int len);
void                append(struct s_draw *ab, const char *s, int len);
struct termios		enable_raw(void);
void                draw_rows(struct s_draw *ab);
void	            disable_raw(struct termios orig_termios);
void                open_edit();
void                init_edit();

void			ft_parse(int ac, char **av);
char			*ft_pathjoin(char *s1, char *s2);
void			ft_cd(int ac, char **new_dir);
void			ft_echo(char **str);
void			ft_putdir(int ac, char **arg);
char			*ft_getenv(char *str);
void			ft_signal();
int				ft_realloc(char **buf, size_t add_to_buf);
void			ft_setenv(int ac, char **value);
void			ft_unsetenv(int ac, char **av);
void			ft_execute(char **com);
void			ft_delenv(char *com);
void			ft_env(int ac, char **com);
int				add_env(char *env, char *value);
void			ft_do(char **inp);
char			*search_bin(char *filename, char *path);
void			free_tab(char **ta, int i);
int				env_err();
char			**empty_cpy();
void			pwd_update(char *new_dir);
void			put_all_env(void);
char			**ft_envcpy(char **environ);
char			**tmp_env_list(int ac, char **com, int *j);
int				check_rights(char *fname);

#endif
