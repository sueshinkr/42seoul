# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:15:20 by sueshin           #+#    #+#              #
#    Updated: 2022/07/18 23:55:16 by sueshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
HEADER = ../include/

SRCS = ./ft_printf_base.c ./ft_printf_csp.c ./ft_printf_diu.c ./ft_printf_xX%.c \
	./ft_printf_xX_flag.c ./ft_printf_util1.c ./ft_printf_util2.c ./ft_printf_util3.c ./ft_printf_diu_flag.c \
	./get_next_line_bonus.c ./get_next_line_utils_bonus.c

BONUS_SRCS = ./get_next_line_bonus.c ./get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) -rcs $(NAME) $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -I$(HEADER)

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus :
	@make OBJS='$(SRCS:.c=.o) $(BONUS_OBJS)'

.PHONY : all clean fclean re bonus

