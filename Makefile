# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wkhosa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/13 15:53:17 by wkhosa            #+#    #+#              #
#    Updated: 2017/09/13 16:28:25 by wkhosa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

IDIR = libft

SRCDIR = .

SRC	= get_next_line.c main.c

OBJ = main.o get_next_line.o

all: 
	make -C libft/ fclean && make -C libft/
	$(CC) $(CFLAGS) -I $(IDIR)  -o get_next_line.o -c get_next_line.c
	$(CC) $(CFLAGS) -I $(IDIR) -o main.o -c main.c
	$(CC) $(CFLAGS) $(OBJ) -I $(IDIR) -L libft/ -lft

clean:
		rm -rf $(OBJ)

fclean: clean

re: fclean all