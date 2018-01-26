# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: husui <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 10:04:33 by husui             #+#    #+#              #
#    Updated: 2018/01/25 16:15:41 by hiroshius        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.out

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Werror -Wextra libft/*.c -I libft/libft.h
	@ar -q libft/libft.a *.o
	@gcc -Llibft -lft *.c -o ft_printf.out

clean:
	@rm -rf *.o *.a libft/*.a libft/*.o

fclean: clean
	@rm -rf ft_printf.out

re: fclean all
