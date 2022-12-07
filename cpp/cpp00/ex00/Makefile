# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 13:09:50 by sueshin           #+#    #+#              #
#    Updated: 2022/12/07 10:01:40 by sueshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(SRCS:.cpp=)
CC = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(SRC))
SRC = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFALGS) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re

