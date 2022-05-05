# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:15:20 by sueshin           #+#    #+#              #
#    Updated: 2022/05/05 13:51:54 by sueshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_printf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
LIB = $(LIB_DIR)/lib$(LIB_NAME).a
LIB_DIR = ./libft
LIB_NAME = ft
HEADER = ./

SRCS = ./ft_printf.c

BONUS_SRCS = 

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	cd $(LIB_DIR); $(MAKE)
	cp $(LIB) ./$(NAME)
	$(AR) -rcs $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -I$(HEADER) -I$(LIB_DIR)

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus :
	@make OBJS='$(SRCS:.c=.o) $(BONUS_OBJS)'

.PHONY : all clean fclean re bonus

