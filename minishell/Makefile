# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 13:09:50 by sueshin           #+#    #+#              #
#    Updated: 2022/12/01 22:01:39 by sueshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIB_DIR = ./lib/
LIB = $(LIB_DIR)libft.a
INCS_DIR = ./include/

#READLINE_LIB	=	-lreadline -L/usr/local/opt/readline/lib
#READLINE_INC	=	-I/usr/local/opt/readline/include
READLINE_LIB	=	-lreadline -L/opt/homebrew/opt/readline/lib
READLINE_INC	=	-I/opt/homebrew/opt/readline/include
#READLINE_LIB	=	-lreadline -L${HOME}/goinfre/.brew/opt/readline/lib
#READLINE_INC	=	-I${HOME}/goinfre/.brew/opt/readline/include

SRCS_DIR = ./src/
SRCS = $(addprefix $(SRCS_DIR), $(SRC))
SRC = test.c signal.c \
	  parse.c interpret_quotes.c interpret_dollar.c \
	  tree.c tree_case_pipe.c tree_case_cmd.c tree_case_rdir.c \
	  ft_cd.c ft_echo.c ft_env.c ft_export.c ft_unset.c ft_exit.c ft_pwd.c \
	  cmd.c cmd_pipe.c cmd_check.c rdir.c rdir_heredoc.c \
	  util1.c util2.c util3.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	@cd lib && make
	$(CC) $(CFALGS) -o $(NAME) $(OBJS) $(READLINE_LIB) $(LIB)

%.o : %.c
	$(CC) $(CFLAGS) ${READLINE_INC} -I$(INCS_DIR) -c -o $@ $<

clean :
	@cd lib && make clean
	rm -f $(OBJS)

fclean : clean
	@cd lib && make fclean
	rm -f $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re

