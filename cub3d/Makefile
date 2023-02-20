# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taehyeok <taehyeok@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:15:20 by sueshin           #+#    #+#              #
#    Updated: 2023/02/19 18:31:10 by taehyeok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -g #-Werror
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit -lz
AR = ar rcs

INCS_DIR = ./include/
SRCS_DIR = ./src/
MLX_DIR = ./mlx/
#SRCS = $(addprefix $(SRCS_DIR), $(SRC))
#SRC = $(wildcard *.c)
SRCS = $(wildcard $(SRCS_DIR)*.c)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(OBJS) $(MLX_FLAGS) -g

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

