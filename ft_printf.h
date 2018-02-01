/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 02:45:37 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/31 03:10:53 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEXADECIMAL_UPPERCASE "0123456789ABCDEF"
# define HEXADECIMAL_LOWERCASE "0123456789abcdef"
# define OCTAL "01234567"
# include <stdarg.h>
# include <stdbool.h>
# include "libft/libft.h"
# include <wchar.h>

typedef struct	s_bag
{
	bool		number_sign;
	bool		zero;
	bool		minus;
	bool		plus;
	bool		space;
	bool		period;
	int			width;
	int			precision;
	char		*length_modifier;
	char		format_conversion;
}				t_bag;

int				ft_printf(char *format, ...);
void			handle_percent(char **format, va_list args, int *i);
char			**set_length_modifiers(void);
bool			in_flags(t_bag *bag, char c);
bool			set_flags(t_bag *bag, char c);
bool			in_format_conversions(char c);
bool			in_length_modifiers(char **length_modifiers,
				char *length_modifier);
char			**set_length_modifiers_array(void);
bool			in_minimum_field_width(char c);
bool			in_precision(char c);
void			print_format_conversion(t_bag *bag, va_list args, int *i);
void			initialize_t_bag_variables(t_bag *bag);
char			*pad_left(char *str, int n, char c);
char			*pad_right(char *str, int n, char c);
char			*cut_left(char *str, int n);
char			*cut_right(char *str, int n);
void			print_s(t_bag *bag, va_list args, int *i);
void			print_s_upper(t_bag *bag, va_list args, int *i);
void			print_p(t_bag *bag, va_list args, int *i);
void			print_d(t_bag *bag, va_list args, int *i);
void			print_i(t_bag *bag, va_list args, int *i);
void			print_o(t_bag *bag, va_list args, int *i);
void			print_u(t_bag *bag, va_list args, int *i);
void			print_x(t_bag *bag, va_list args, int *i);
void			print_c(t_bag *bag, va_list args, int *i);
char			*print_d_plus(t_bag *bag, char *input);
char			*print_d_space(t_bag *bag, char *input);
char			*print_d_width(t_bag *bag, char *input);
char			*print_d_precision(t_bag *bag, char *input);
char			*print_o_plus(t_bag *bag, char *input);
char			*print_o_space(t_bag *bag, char *input);
char			*print_o_width(t_bag *bag, char *input);
char			*print_o_precision(t_bag *bag, char *input);
char			*print_o_number_sign(t_bag *bag, char *input);
char			*print_u_plus(t_bag *bag, char *input);
char			*print_u_space(t_bag *bag, char *input);
char			*print_u_width(t_bag *bag, char *input);
char			*print_u_precision(t_bag *bag, char *input);
char			*print_x_plus(t_bag *bag, char *input);
char			*print_x_space(t_bag *bag, char *input);
char			*print_x_width(t_bag *bag, char *input);
char			*print_x_precision(t_bag *bag, char *input);
char			*print_x_number_sign(t_bag *bag, char *input);
void			print_percent(t_bag *bag, int *i);
int				power_i(int number, int exponent);
long			power_l(long number, int exponent);
char			*ft_ltoa(long n);
void			truncate_zeros(char **str);
int				number_cmp(char *str1, char *str2);
bool			zeroed(char *str);
char			*stringerize(char c);

bool			g_is_print_p;
#endif
