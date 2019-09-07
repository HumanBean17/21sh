LIB = libft/libft.a

HEADER = ./minishell.h

SRC_BUILT = builtins/cd/chdir.c builtins/cd/pwd_update.c builtins/echo/echo.c \
			builtins/env/env.c builtins/env/env2.c builtins/pwd/pwd.c \
			builtins/setenv/setenv.c builtins/unsetenv/unsetenv.c \

SRC_TTY = tty/set_attr.c

SRC_EXEC = execute/execute.c

SRC_PARSE = parse/parse.c

SRC_SIGNAL = signal/signal.c

SRC_ERR = error/perror.c

SRC_SUP = sup/support.c

SRC =	$(SRC_BUILT) \
		$(SRC_EXEC) \
		$(SRC_PARSE) \
		$(SRC_SIGNAL) \
		$(SRC_SUP) \
		$(SRC_ERR) \
		main.c

OBJ =   chdir.o echo.o env.o env2.o execute.o parse.o perror.o pwd.o \
        pwd_update.o setenv.o signal.o support.o unsetenv.o main.o

NAME = minishell

GCC = gcc -Wall -Wextra -Werror

all: $(NAME)
$(NAME): $(LIB) $(OBJ)
	$(GCC) -o $(NAME) -I $(HEADER) -L. $(LIB) $(OBJ)
$(OBJ):
	gcc -c $(SRC)
$(LIB):
	make -C ./libft
clean:
	rm -rf $(OBJ)
	make clean -C ./libft
fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft
re: fclean all