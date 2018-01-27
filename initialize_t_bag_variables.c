#include "ft_printf.h"

void	initialize_t_bag_variables(t_bag *bag)
{
	bag->number_sign = 0;
	bag->zero = 0;
	bag->minus = 0;
	bag->plus = 0;
	bag->space = 0;
	bag->width = 0;
	bag->precision = 0;
	bag->length_modifier = "";
	bag->format_conversion = 0;
}
