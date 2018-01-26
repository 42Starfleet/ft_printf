# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: husui <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 16:06:07 by husui             #+#    #+#              #
#    Updated: 2017/11/30 10:12:55 by husui            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAG = -c -Wall -Werror -Wextra
SRC = *.c
OBJ = *.o
HDR = -I libft.h
RM = rm -rf

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAG) $(SRC) $(HDR)
	@ar -q $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
