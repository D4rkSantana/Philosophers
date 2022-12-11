# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 23:20:29 by esilva-s          #+#    #+#              #
#    Updated: 2022/12/09 19:46:24 by esilva-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
INCLUDES = -I philosophers.h
RM = rm -rf

SRC =	beholder.c build_tools.c build.c check_args.c destroy.c forks_tools.c \
		main.c mutex_tools.c philos_tools.c routine.c timestamp.c tools.c

OBG = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBG)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBG) -o $(NAME)

$(OBG): $(SRC)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC)

clean:
	$(RM) $(OBG)

fclean: clean
	$(RM) $(NAME)

re: fclean all

cclean: all clean
	clear
