# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:15:20 by sueshin           #+#    #+#              #
#    Updated: 2022/07/10 21:47:25 by sueshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solong
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS	= -L./mlx -lmlx -framework OpenGL -framework Appkit -lz
AR = ar rcs

INCS_DIR = ./include/
SRCS_DIR = ./src/
MLX_DIR = ./mlx/
SRCS = $(addprefix $(SRCS_DIR), $(SRC))
SRC = main.c map.c render.c util.c get_next_line_bonus.c get_next_line_utils_bonus.c \
	exit.c key_event.c animation.c player_animation.c 
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_DIR)
	$(CC) -o $(NAME) $(OBJS) -L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit -lz

%.o : %.c
#	$(CC) $(CFLAGS) -I$(INCS_DIR) -c -o $@ $<
	$(CC) -g -I$(INCS_DIR) -c -o $@ $<

clean :
	make -C $(MLX_DIR) clean 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : 
	make fclean
	make all

bonus : $(NAME)

.PHONY : all clean fclean re bonus

