# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueshin <sueshin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 13:09:50 by sueshin           #+#    #+#              #
#    Updated: 2022/12/14 16:23:51 by sueshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = intern
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

INCS_DIR = ./
SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(SRC))
SRC = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFALGS) -I$(INCS_DIR) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCS_DIR) -c -o $@ $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re

