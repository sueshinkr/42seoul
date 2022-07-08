# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:15:20 by sueshin           #+#    #+#              #
#    Updated: 2022/07/07 23:59:11 by sueshin          ###   ########.fr        #
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
SRC = main.c map.c get_next_line.c get_next_line_utils.c exit.c key_event.c
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

