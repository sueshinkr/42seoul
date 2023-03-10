# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 13:09:50 by sueshin           #+#    #+#              #
#    Updated: 2023/02/27 16:48:23 by sueshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = serv

CC = c++ -std=c++98
#CC = c++ -Wall -Wextra -Werror -std=c++98 
#CXXFLAGS = -Wall -Wextra -Werror -std=c++98 

INCS_DIR = ./include/
MAIN_INC = -I$(INCS_DIR)
INCS = $(addprefix $(INCS_DIR), $(INC))
INC = $(wildcard *.hpp)

SRCS_DIR = ./srcs/
#SRCS = $(addprefix $(SRCS_DIR), config.cpp \
		socket.cpp \
		main.cpp)
SRCS = $(wildcard $(SRCS_DIR)*.cpp)

#SRCS = $(wildcard *.cpp)

#OBJS = $(SRCS:.cpp=.o)
OBJS_DIR	= ./objects/
OBJS		= $(SRCS:$(SRCS_DIR)%.cpp=$(OBJS_DIR)%.o)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.cpp
			@mkdir -p $(OBJS_DIR)
			@echo "[..] $(NAME_SHORT)... compiling $*.cpp\r\c"
			@$(CC) $(MAIN_INC) -c $< -o $@
			@echo "$(_CLEAR)"

all : $(NAME)

$(NAME) : $(OBJS) $(INCS)
			@$(CC) $(OBJS) $(MAIN_INC) -o $(NAME)

#$(NAME): $(OBJS)
#	$(CC) $(CXXFLAGS) -I$(INCS_DIR) -o $(NAME) $(OBJS)

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
