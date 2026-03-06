# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: banne <banne@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/25 12:51:57 by banne             #+#    #+#              #
#    Updated: 2026/03/06 12:57:02 by banne            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo
CC=cc
CFLAGS=-Wall -Wextra -Werror -pthread
SRCS=srcs/main.c \
	srcs/free.c \
	srcs/monitor.c \
	srcs/init.c \
	srcs/routine.c \
	srcs/parsing.c \
	srcs/time.c \
	srcs/needed.c \
	srcs/utils.c
OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
 
.PHONY: all clean fclean re