LIB = libft/libft.a

HEADER = ./includes

SRC_BUILT = ./builtins/*.c

SRC_TTY = ./tty/*.c

SRC_EXEC = ./execute/*.c

SRC_PARSE = ./parse/*.c

SRC_SIGNAL = ./signal/*.c

SRC_ERR = error/*.c

SRC_SUP = sup/*.c

SRC =	$(SRC_BUILT) \
		$(SRC_EXEC) \
		$(SRC_PARSE) \
		$(SRC_SIGNAL) \
		$(SRC_SUP) \
		$(SRC_ERR) \
		$(SRC_TTY)

OBJ =   *.o

NAME = minishell

GCC = gcc

all: $(OBJ) $(LIB) $(NAME)

$(NAME):
	$(GCC) -o $(NAME) -I $(HEADER) $(OBJ) -L. $(LIB)

$(OBJ):
	gcc -c $(SRC) -I $(HEADER)

$(LIB):
	make -C ./libft

clean:
	rm -rf $(OBJ)
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft

re: fclean all