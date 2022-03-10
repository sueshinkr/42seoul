# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:15:20 by sueshin           #+#    #+#              #
#    Updated: 2022/03/10 14:40:47 by sueshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar

HEADER = .
SRCS = ./main.c ./ft_isascii.c ./ft_isprint.c ./ft_strlen.c ./ft_memset.c ./ft_memcpy.c ./ft_memmove.c ./ft_strlcpy.c
OBJS = $(SRCS:.c=.o)
 
all: $(NAME)
 
%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(HEADER)
 
libft.a : $(OBJS)
	$(AR) rcs $@ $^

$(NAME): libft.a
	$(CC) $(CFLAGS) -o $(NAME) libft.a
	
clean:
	rm -f $(OBJS)
 
fclean: clean
	rm -f $(NAME)
 
re: fclean all

.PHONY : all clean fclean re
