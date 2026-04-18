# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aseveri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/09 20:43:00 by aseveri           #+#    #+#              #
#    Updated: 2026/04/17 15:11:55 by aseveri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= do-op
SRC		= srcs/main.c srcs/ft_tool_write.c srcs/ft_operator.c
OBJ		= $(SRC:.c=.o)
LIB		= includes/ft_tail.h
CC		= gcc
RFLAGS	= -Wall -Wextra -Werror
CFLAGS  = -Wall -Wextra -Werror -I includes
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(RFLAGS) $(OBJ) -o $(NAME)

srcs/%.o: srcs/%.c $(LIB)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
