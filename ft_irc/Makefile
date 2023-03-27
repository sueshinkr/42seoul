# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 13:09:50 by sueshin           #+#    #+#              #
#    Updated: 2023/03/20 13:17:59 by taehyeok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ircserv
NAMEB = ircserv_bonus

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

INCS_DIR = ./includes/
MAIN_INC = -I$(INCS_DIR)
INCS = $(addprefix $(INCS_DIR), $(INC))
INC = $(wildcard *.hpp)

INCS_DIRB = ./includes_bonus/
MAIN_INCB = -I$(INCS_DIRB)
INCSB = $(addprefix $(INCS_DIRB), $(INCB))
INCB = $(wildcard *.hpp)

SRCS_DIR = ./src/
SRCS = $(wildcard $(SRCS_DIR)*.cpp)

SRCS_DIRB = ./src_bonus/
SRCSB = $(wildcard $(SRCS_DIRB)*.cpp)

OBJS_DIR	= ./objects/
OBJS		= $(SRCS:$(SRCS_DIR)%.cpp=$(OBJS_DIR)%.o)
OBJSB		= $(SRCSB:$(SRCS_DIRB)%.cpp=$(OBJS_DIR)%.o)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.cpp
			@mkdir -p $(OBJS_DIR)
			@echo "[..] $(NAME_SHORT)... compiling $*.cpp\r\c"
			@$(CXX) $(CXXFLAGS) $(MAIN_INC) -c $< -o $@
			@echo "$(_CLEAR)"

$(OBJS_DIR)%.o : $(SRCS_DIRB)%.cpp
			@mkdir -p $(OBJS_DIR)
			@echo "[..] $(NAME_SHORT)... compiling $*.cpp\r\c"
			@$(CXX) $(CXXFLAGS) $(MAIN_INCB) -c $< -o $@
			@echo "$(_CLEAR)"

all : $(NAME)

bonus : $(NAMEB)

$(NAME) : $(OBJS) $(INCS)
			$(CXX) $(OBJS) $(CXXFLAGS) $(MAIN_INC) -o $(NAME)


$(NAMEB) : $(OBJSB) $(INCSB)
			$(CXX) $(OBJSB) $(CXXFLAGS) $(MAIN_INCB) -o $(NAMEB)

clean :
	rm -f $(OBJS) $(OBJSB)

fclean : clean
	rm -f $(NAME) $(NAMEB)

re : 
	make fclean
	make all


.PHONY : all clean fclean re
