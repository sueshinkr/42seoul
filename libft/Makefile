# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:15:20 by sueshin           #+#    #+#              #
#    Updated: 2022/03/10 19:13:26 by sueshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft
LIBNAME = $(NAME).a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar

HEADER = .
SRCS = ./main.c ./ft_isalnum.c ./ft_isalpha.c ./ft_isascii.c\
./ft_isdigit.c ./ft_isprint.c ./ft_strlen.c ./ft_memset.c\
./ft_bzero.c ./ft_memcpy.c ./ft_memmove.c ./ft_strlcpy.c\
./ft_strlcat.c ./ft_strncmp.c ./ft_toupper.c ./ft_tolower.c\
./ft_strchr.c ./ft_strrchr.c ./ft_memchr.c ./ft_memcmp.c\
./ft_strnstr.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) -rcs $(LIBNAME) $^
	$(CC) $(CFLAGS) -o $(NAME) $(LIBNAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(HEADER)
	
clean:
	rm -f $(OBJS)
 
fclean: clean
	rm -f $(NAME) libft.a
 
re: fclean all

.PHONY : all clean fclean re
