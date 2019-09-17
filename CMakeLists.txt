cmake_minimum_required(VERSION 3.14)
project(21sh C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)
include_directories(libft)

add_executable(21sh
        builtins/chdir.c
        builtins/echo.c
        builtins/env.c
        builtins/env2.c
        builtins/pwd.c
        builtins/pwd_update.c
        builtins/setenv.c
        builtins/unsetenv.c
        error/perror.c
        execute/execute.c
        includes/error.h
        includes/libft.h
        includes/minishell.h
        libft/ft_bzero.c
        libft/ft_count_str.c
        libft/ft_isprint.c
        libft/ft_itoa.c
        libft/ft_max.c
        libft/ft_memalloc.c
        libft/ft_memchr.c
        libft/ft_memcpy.c
        libft/ft_memset.c
        libft/ft_putchar_fd.c
        libft/ft_putstr_fd.c
        libft/ft_strcat.c
        libft/ft_strchr.c
        libft/ft_strclen.c
        libft/ft_strcmp.c
        libft/ft_strdel.c
        libft/ft_strdup.c
        libft/ft_strjoin.c
        libft/ft_strlen.c
        libft/ft_strncmp.c
        libft/ft_strnew.c
        libft/ft_strsplit.c
        libft/ft_strstr.c
        libft/ft_strsub.c
        libft/ft_strtok.c
        libft/ft_strwdup.c
        libft/ft_strwlen.c
        libft/libft.h
        line_edit/draw.c
        line_edit/edit.c
        parse/main.c
        parse/parse.c
        realloc/realloc.c
        signal/signal.c
        sup/support.c
        tty/set_attr.c term/term_init.c term/key_move.c term/delete.c)
