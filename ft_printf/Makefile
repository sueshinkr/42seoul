# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:15:20 by sueshin           #+#    #+#              #
#    Updated: 2022/05/29 14:33:37 by sueshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
HEADER = ./

SRCS = ./ft_printf_base_bonus.c ./ft_printf_csp_bonus.c ./ft_printf_diu_bonus.c ./ft_printf_xX%_bonus.c\
./ft_printf_xX_flag_bonus.c ./ft_printf_util_bonus.c ./ft_printf_diu_flag_bonus.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) -rcs $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -w -c $^ -I$(HEADER)
	
clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus

