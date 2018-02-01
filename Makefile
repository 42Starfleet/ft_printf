# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: husui <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 10:04:33 by husui             #+#    #+#              #
#    Updated: 2018/01/31 21:03:21 by scamargo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
TEST = ft_printf.out
LIB	= libft.a
SRCS = cut_left.c cut_right.c ft_printf.c handle_percent.c in_flags.c in_format_conversions.c \
	   in_length_modifiers.c in_minimum_field_width.c in_precision.c initialize_t_bag_variables.c \
	   pad_left.c pad_right.c print_c.c print_d.c print_format_conversion.c print_o.c\
	   print_p.c print_percent.c print_s.c print_u.c print_x.c set_flags.c set_length_modifiers.c \
	   ft_intmax_toa.c test_printd.c print_u_precision.c print_u_width.c stringerize.c ft_ltoa.c \
		number_cmp.c truncate_zeros.c zeroed.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME) 

$(NAME):
	@gcc -c $(SRCS)
	@ar -q $(NAME) *.o

$(LIB):
	@gcc -c -Wall -Werror -Wextra libft/*.c -I libft/libft.h
	@ar -q libft/$(LIB) *.o
	@cp libft/$(LIB) .

test:
	@gcc -g -L. -lftprintf -lft $(SRCS) main.c -o $(TEST)
 
clean:
	@rm -rf *.o libft/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIB)

re: fclean $(LIB) all
