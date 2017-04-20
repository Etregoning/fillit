# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etregoni <etregoni@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/21 04:37:44 by etregoni          #+#    #+#              #
#    Updated: 2017/03/21 04:37:47 by etregoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIB = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -rf

SRC = main.c validation.c create_piece.c game_board.c solver.c tables.c \
	trimmer.c
	
LIBSRC = ft_putchar.c ft_putstr.c ft_strcpy.c ft_strnew.c ft_strdel.c \
	ft_strequ.c ft_putendl.c ft_error.c

LIBLIST  :=  $(shell ls -1 libft | grep .c$$)
LIBOBJ   :=  $(LIBLIST:.c=.o)
LIBOBJ   :=  $(addprefix libft/, $(LIBOBJ))

SRCLIST  :=  $(shell ls -1 src | grep .c$$)
SRCOBJ   :=  $(SRCLIST:.c=.o)
SRCOBJ   :=  $(addprefix src/, $(SRCOBJ))

.PHONY: all clean fclean re

all: $(NAME)

libft/%.o: libft/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

lib:
	ar rc $(LIB) $(LIBOBJ)
	ranlib $(LIB)

debug:
	$(CC) $(CFLAGS) $(addprefix libft/, $(LIBLIST)) $(addprefix src/, $(SRCLIST)) -g -o fillit

$(NAME): $(LIBOBJ) $(SRCOBJ) lib
	$(CC) $(CFLAGS) $(SRCOBJ) -L. -lft -o fillit

clean:
	$(RM) $(SRCOBJ)
	$(RM) $(LIBOBJ)


fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIB)

re: fclean all

re-db: fclean debug
