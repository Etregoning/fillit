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

SRC = main.c
LIBSRC = ft_putchar.c ft_putstr.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_putnbr.c \
	ft_strcmp.c ft_strncmp.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_isalnum.c \
	ft_isalpha.c ft_isdigit.c ft_isprint.c ft_isascii.c ft_toupper.c ft_tolower.c \
	ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_atoi.c ft_strncpy.c \
	ft_memset.c ft_memcpy.c ft_bzero.c ft_memmove.c ft_memccpy.c ft_memchr.c \
	ft_memcmp.c ft_memalloc.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
	ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
	ft_itoa.c ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_lstnew.c \
	ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	ft_memdel.c ft_strrev.c ft_itoa_base.c ft_countdigits.c ft_isupper.c \
	ft_islower.c



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

debug: $(LIBOBJ) $(SRCOBJ) lib
	$(CC) $(CFLAGS) -g $(SRCOBJ) -L. -lft -o fillit

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
