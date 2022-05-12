# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:15:20 by sueshin           #+#    #+#              #
#    Updated: 2022/05/12 10:32:05 by sueshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
LIB = $(LIB_DIR)/libft.a
LIB_DIR = ./libft
HEADER = ./

SRCS = ./ft_printf_base.c ./ft_printf_csp.c ./ft_printf_diu.c ./ft_printf_xX.c

BONUS_SRCS = 

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) -rcs $@ $^

%.o : %.c
	cd $(LIB_DIR); $(MAKE)
	cp $(LIB) ./$(NAME)
	$(CC) $(CFLAGS) -c $^ -I$(HEADER) -I$(LIB_DIR)

clean :
	rm -f $(OBJS) $(BONUS_OBJS)
	cd $(LIB_DIR); $(MAKE) clean

fclean : clean
	rm -f $(NAME)
	rm -f $(LIB)

re : fclean all

bonus :
	@make OBJS='$(SRCS:.c=.o) $(BONUS_OBJS)'

.PHONY : all clean fclean re bonus

