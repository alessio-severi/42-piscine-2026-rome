# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aseveri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/09 20:43:00 by aseveri           #+#    #+#              #
#    Updated: 2026/04/09 21:04:46 by aseveri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_tail
SRC		= main.c tool.c
OBJ		= $(SRC:.c=.o)
LIB		= includes/ft_tail.h
CC		= gcc
RFLAGS	= -Wall -Wextra -Werror
CFLAGS  = -Wall -Wextra -Werror -I includes
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(RFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(LIB)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
