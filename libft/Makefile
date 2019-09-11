# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarti <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 14:18:02 by mmarti            #+#    #+#              #
#    Updated: 2019/04/12 14:18:07 by mmarti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFILE = ft_memalloc.c ft_bzero.c ft_strcat.c ft_strclen.c ft_strwlen.c \
		ft_strcmp.c ft_memcpy.c ft_strdup.c ft_strchr.c ft_strsplit.c \
		ft_putchar_fd.c ft_strlen.c ft_putstr_fd.c ft_count_str.c ft_strtok.c \
		ft_strwdup.c ft_memchr.c ft_strncmp.c

OFILE = $(CFILE:.c=.o)

HFILE = libft.h

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -I .$(HFILE) -c $(CFILE)
	ar rc $(NAME) $(OFILE)
	ranlib $(NAME)

clean: 
	/bin/rm -f $(OFILE)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all


