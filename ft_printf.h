#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdbool.h>
# include "libft/libft.h"
# include <locale.h>
# include <wchar.h>
# include <stdio.h>

typedef struct	s_bag
{
	bool		number_sign;
	bool		zero;
	bool		minus;
	bool		plus;
	bool		space;
	int			width;
	int			precision;
	char		*length_modifier;
	char		format_conversion;
}				t_bag;

int				ft_printf(char *format, ...);
// Set return type to t_bag * for unit testing purposes.
//t_bag			*handle_percent(char **format, va_list args, int *i);
void			handle_percent(char **format, va_list args, int *i);
char			**set_length_modifiers(void);
bool			in_flags(t_bag *bag, char c);
bool			set_flags(t_bag *bag, char c);
bool			in_format_conversions(char c);
bool			in_length_modifiers(char **length_modifiers, char *length_modifier);
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
void			print_p(t_bag *bag, va_list args, int *i);
void			print_d(t_bag *bag, va_list args, int *i);
void			print_i(t_bag *bag, va_list args, int *i);
void			print_o(t_bag *bag, va_list args, int *i);
void			print_u(t_bag *bag, va_list args, int *i);
void			print_x(t_bag *bag, va_list args, int *i);
void			print_c(t_bag *bag, va_list args, int *i);
void			print_percent(t_bag *bag, va_list args, int *i);
#endif
