# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:15:20 by sueshin           #+#    #+#              #
#    Updated: 2023/02/14 15:42:06 by sueshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -g #-Werror
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit -lz
AR = ar rcs

INCS_DIR = ./include/
SRCS_DIR = ./srctemp/
MLX_DIR = ./mlx/
#SRCS = $(addprefix $(SRCS_DIR), $(SRC))
#SRC = $(wildcard *.c)
SRCS = $(wildcard $(SRCS_DIR)*.c)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(OBJS) $(MLX_FLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCS_DIR) -c -o $@ $<

clean :
	make -C $(MLX_DIR) clean 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re bonus
.SILENT : all

