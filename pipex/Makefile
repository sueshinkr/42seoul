# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:15:20 by sueshin           #+#    #+#              #
#    Updated: 2022/07/26 17:03:11 by sueshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

LIB_DIR = ./lib/
LIB = $(LIB_DIR)libft.a
INCS_DIR = ./include/

SRCS_DIR = ./src/
SRCS = $(addprefix $(SRCS_DIR), $(SRC))
SRC = main.c read.c open.c check.c pipe.c free.c util.c util2.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	@cd lib && make
	$(CC) $(CFALGS) -o $(NAME) $(OBJS) $(LIB)

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCS_DIR) -c -o $@ $<

clean :
	@cd lib && make clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	@cd lib && make fclean
	rm -f $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re

