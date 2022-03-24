# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 13:53:05 by jabae             #+#    #+#              #
#    Updated: 2022/03/24 19:05:13 by jabae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC		    = gcc 
CFLAGS		= -Wall -Wextra -Werror

AR			  = ar
ARFLAGS		= rcs

SRCS		=	ft_printf.c\
				ft_printf_format.c\
				ft_printf_utils.c\

OBJS		= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re:
	fclean all

.PHONY : all clean fclean re
