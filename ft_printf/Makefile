# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:15:20 by sueshin           #+#    #+#              #
#    Updated: 2022/06/02 16:13:19 by sueshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
HEADER = ./

SRCS = ./ft_printf_base.c ./ft_printf_csp.c ./ft_printf_diu.c ./ft_printf_xX%.c\
./ft_printf_xX_flag.c ./ft_printf_util1.c ./ft_printf_util2.c ./ft_printf_util3.c ./ft_printf_diu_flag.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) -rcs $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -I$(HEADER)
	
clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re bonus

