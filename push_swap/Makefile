# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:15:20 by sueshin           #+#    #+#              #
#    Updated: 2022/07/20 16:53:04 by sueshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

LIB_DIR = ./lib/
LIB = $(LIB_DIR)libft.a
INCS_DIR = ./include/

SRCS_DIR = ./src/
SRCS = $(addprefix $(SRCS_DIR), $(SRC))
SRC = main.c init.c read.c command.c move1.c move2.c pivot.c check.c util.c free.c \
	sort_firstlast.c sort_select.c sort_atob.c sort_btoa.c sort_only.c sort_three.c sort_four.c
OBJS = $(SRCS:.c=.o)

BONUS_SRCS_DIR = ./bonus/
BONUS_SRCS = $(addprefix $(BONUS_SRCS_DIR), $(BONUS_SRC))
BONUS_SRC = main.c init.c read.c util.c check.c move1.c move2.c free.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	@cd lib && make
	$(CC) $(CFALGS) -o $(NAME) $(OBJS) $(LIB)

$(BONUS_NAME): $(BONUS_OBJS)
	@cd lib && make bonus
	$(CC) $(CFLAGS) -g -o $(BONUS_NAME) $(BONUS_OBJS) $(LIB)

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCS_DIR) -g -c -o $@ $<

clean :
	@cd lib && make clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	@cd lib && make fclean
	rm -f $(NAME) $(BONUS_NAME)

re : 
	make fclean
	make all

bonus : $(BONUS_NAME)

.PHONY : all clean fclean re bonus

