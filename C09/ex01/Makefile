# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aseveri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/07 03:01:28 by aseveri           #+#    #+#              #
#    Updated: 2026/04/07 03:10:21 by aseveri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRC		= srcs/ft_putchar.c \
		  srcs/ft_swap.c \
      	  srcs/ft_putstr.c \
      	  srcs/ft_strlen.c \
      	  srcs/ft_strcmp.c
OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I includes
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

srcs/%.o: srcs/%.c includes/ft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	${RM} $(OBJ)

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re