# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:15:20 by sueshin           #+#    #+#              #
#    Updated: 2022/08/17 22:39:13 by sueshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

LIB_DIR = ./lib/
LIB = $(LIB_DIR)libft.a
INCS_DIR = ./include/

SRCS_DIR = ./src/
SRCS = $(addprefix $(SRCS_DIR), $(SRC))
SRC = main.c init.c action.c check.c util.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFALGS) -o $(NAME) $(OBJS) -lpthread
#	$(CC) $(CFALGS) -o $(NAME) $(OBJS) -lpthread -fsanitize=address -static-libasan

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCS_DIR) -c -o $@ $<
#	$(CC) $(CFLAGS) -fsanitize=address -g -I$(INCS_DIR) -c -o $@ $<

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re

