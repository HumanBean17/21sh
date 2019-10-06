LIB = libft/libft.a

HEADER = ./includes

SRC_BUILT = ./builtins/*.c

SRC_TTY = ./tty/*.c

SRC_EXEC = ./execute/*.c

SRC_PARSE = ./parse/*.c

SRC_SIGNAL = ./signal/*.c

SRC_ERR = error/*.c

SRC_SUP = sup/*.c

SRC_EDT = line_edit/*.c

SRC_RLC = realloc/*.c

SRC_TMP = term/*.c

SRC_PRT = print/*.c

SRC_ANAL = analyzer/*.c

SRC =	$(SRC_BUILT) \
		$(SRC_EXEC) \
		$(SRC_PARSE) \
		$(SRC_SIGNAL) \
		$(SRC_SUP) \
		$(SRC_ERR) \
		$(SRC_TTY) \
		$(SRC_EDT) \
		$(SRC_RLC) \
		$(SRC_TMP) \
		$(SRC_PRT) \
		$(SRC_ANAL)

OBJ =   *.o

NAME = 21sh

GCC = gcc

all: $(OBJ) $(LIB) $(NAME)

$(NAME): $(OBJ)
	$(GCC) -o $(NAME) -I $(HEADER) $(OBJ) -L. $(LIB) -ltermcap

$(OBJ): $(SRC)
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