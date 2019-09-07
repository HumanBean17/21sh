cmake_minimum_required(VERSION 3.14)
project(new_21sh C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(error)
include_directories(libft)

add_executable(new_21sh
        builtins/cd/chdir.c
        builtins/cd/pwd_update.c
        builtins/echo/echo.c
        builtins/env/env.c
        builtins/env/env2.c
        builtins/pwd/pwd.c
        builtins/setenv/setenv.c
        builtins/unsetenv/unsetenv.c
        error/error.h
        error/perror.c
        execute/execute.c
        libft/ft_bzero.c
        libft/ft_count_str.c
        libft/ft_memalloc.c
        libft/ft_memchr.c
        libft/ft_memcpy.c
        libft/ft_putchar_fd.c
        libft/ft_putstr_fd.c
        libft/ft_strcat.c
        libft/ft_strchr.c
        libft/ft_strclen.c
        libft/ft_strcmp.c
        libft/ft_strdup.c
        libft/ft_strlen.c
        libft/ft_strncmp.c
        libft/ft_strsplit.c
        libft/ft_strstr.c
        libft/ft_strtok.c
        libft/ft_strwdup.c
        libft/ft_strwlen.c
        libft/libft.h
        parse/parse.c
        signal/signal.c
        sup/support.c
        main.c
        minishell.h tty/set_attr.c)
