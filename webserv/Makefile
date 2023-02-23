# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 13:09:50 by sueshin           #+#    #+#              #
#    Updated: 2023/02/23 14:40:35 by sueshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serv
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

INCS_DIR = ./
SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(SRC))
SRC = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) -I$(INCS_DIR) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CXXFLAGS) -I$(INCS_DIR) -c -o $@ $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re

