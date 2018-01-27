# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: husui <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 10:04:33 by husui             #+#    #+#              #
#    Updated: 2018/01/26 22:01:06 by scamargo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.out
LIB	= libft.a

all: $(NAME)

$(NAME):
	@gcc -Llibft -lft *.c -o ft_printf.out

%.o: %.c
	@gcc -Llibft -lft $< -o ft_printf.out

$(LIB):
	@gcc -c -Wall -Werror -Wextra libft/*.c -I libft/libft.h
	@ar -q libft/$(LIB) *.o
 
clean:
	@rm -rf *.o *.a libft/*.a libft/*.o

fclean: clean
	@rm -rf ft_printf.out

re: fclean all
