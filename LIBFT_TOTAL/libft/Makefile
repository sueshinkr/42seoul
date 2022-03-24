# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:15:20 by sueshin           #+#    #+#              #
#    Updated: 2022/03/24 14:08:07 by sueshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
HEADER = ./

SRCS = ./ft_isalnum.c ./ft_isalpha.c ./ft_isascii.c\
./ft_isdigit.c ./ft_isprint.c ./ft_strlen.c ./ft_memset.c\
./ft_bzero.c ./ft_memcpy.c ./ft_memmove.c ./ft_strlcpy.c\
./ft_strlcat.c ./ft_strncmp.c ./ft_toupper.c ./ft_tolower.c\
./ft_strchr.c ./ft_strrchr.c ./ft_memchr.c ./ft_memcmp.c\
./ft_strnstr.c ./ft_atoi.c ./ft_calloc.c ./ft_strdup.c\
./ft_substr.c ./ft_strjoin.c ./ft_strtrim.c ./ft_split.c\
./ft_itoa.c ./ft_strmapi.c ./ft_striteri.c ./ft_putchar_fd.c\
./ft_putstr_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c\

BONUS_SRCS = ./ft_lstnew.c ./ft_lstadd_front.c ./ft_lstsize.c ./ft_lstlast.c\
./ft_lstadd_back.c ./ft_lstclear.c ./ft_lstdelone.c ./ft_lstiter.c ./ft_lstmap.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
 
fclean: clean
	rm -f $(NAME) $(LIBNAME)
	 
re: fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) -rcs $(NAME) $^

so:
	$(CC) -fPIC $(CFLAGS) $(SRCS) $(BONUS_SRCS)
	gcc -shared -o libft.so $(OBJS) $(BONUS_OBJS)

$(NAME): $(OBJS)
	$(AR) -rcs $(NAME) $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(HEADER)

.PHONY : all clean fclean re bonus so 

