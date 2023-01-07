# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueshin <sueshin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:15:20 by sueshin           #+#    #+#              #
#    Updated: 2023/01/07 09:18:11 by sueshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit -lz
AR = ar rcs

INCS_DIR = ./include/
SRCS_DIR = ./src/
MLX_DIR = ./mlx/
SRCS = $(addprefix $(SRCS_DIR), $(SRC))
SRC = $(wildcard *.cpp)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
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

