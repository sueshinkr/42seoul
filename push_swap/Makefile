# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:15:20 by sueshin           #+#    #+#              #
#    Updated: 2022/07/16 16:11:32 by sueshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

INCS_DIR = ./include/
SRCS_DIR = ./src/
MLX_DIR = ./mlx/
SRCS = $(addprefix $(SRCS_DIR), $(SRC))
SRC = main.c init.c read.c command.c move1.c move2.c pivot.c check.c util.c free.c\
	sort_firstlast.c sort_select.c sort_atob.c sort_btoa.c sort_only.c sort_three.c sort_four.c \
	ft_printf_base.c ft_printf_csp.c ft_printf_diu.c ft_printf_xX%.c\
	ft_printf_xX_flag.c ft_printf_util1.c ft_printf_util2.c ft_printf_util3.c ft_printf_diu_flag.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCS_DIR) -c -o $@ $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : 
	make fclean
	make all

bonus : $(NAME)

.PHONY : all clean fclean re bonus

