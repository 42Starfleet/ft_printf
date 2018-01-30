#include "ft_printf.h"

/*
**	Source: https://www-user.tu-chemnitz.de/~heha/petzold/ch02c.htm
**	A note on capital letter (wide) conversion types: "Nothing about Unicode
**	or wide characters alters the meaning of the char data type in C. The char
**	continues to indicate 1 byte of storage, and sizeof(char) continues to
**	return 1. In theory, a byte in C can be greater than 8 bits, but for most
**	of us, a byte (and hence a char) is 8 bits wide.
**
**	Wide characters in C are based on the "wchar_t" data type, which is defined
**	in several headers files, including "<wchar.h>", like so:
**	"typedef unsigned short wchar_t;"
**
**	Thus, the "wchar_t" data type is the same as an unsigned short integer:
**	16 bits wide.
**
**	Source: The C Programming Language, 2nd Edition (Dennis Ritchie), page 137
**	&&
**	Source: C Primer Plus 6th Edition, page 113
**
**	*******************************Mandatory Part*******************************
**	Types of conversions:
**
**	s S p d D i o O u U x X c C
**	s: Print characters from the string until a '\0' or the number of
**	characters given by the precision
**
**	S: Equivalent of "%ls"
**
**	p: Pointer
**
**	d: Signed decimal integer
**
**	D: Equivalent of "%ld"
**
**	i: Equivalent of 'd'
**
**	o: Unsigned octal number (without a leading zero)
**
**	u: Unsigned decimal number
**
**	U: Equivalent of "%lu"
**
**	x: Unsigned hexadecimal number (without a leading 0x), using abcdef
**	for 10, ..., 15.
**
**	X: Unsigned hexadecimal number (without a leading 0X), using ABCDEF
**	for 10, ..., 15.
**
**	c: Single character
**
**	C: Equivalent of "%lc"
**
**	Length modifiers:
**	Modifier		d, i			o, u, x, X			n
**	hh				signed char		unsigned char		signed char *
**	h				short			unsigned short		short *
**	l (ell)			long			unsigned long		long *
**	ll (ell ell)	long long		unsigned long long	long long *
**	j				intmax_t		uintmax_t			intmax_t *
**	z				(see note)		size_t				(see note)
**
**	Flags:
**	#: A "#" character sepcifies that the value should be printed in
**	"alternate" form.
**	This option has no effect on "b, c, d, s," and "u" formats.
**	For the o formats, the precision of the number increases to make the first
**	character of the outputted string to be zero.
**	For the x/X format, a non-zero string has the string 0x/0X prepended to it.
**	For "a, A, e, E, f, F, g, and G formats", the result always has a decimal.
**	For "g and G" formats, trailing zeros are not removed from the result as
**	they usually would be.
**	0: A "0" character indicates that zero-padding should be used rather than
**	blank padding. A "-" overrides a "0" if both are used. If a numeric
**	conversion is given (d, i, o, u, i, x, and X), then the '0' flag is ignored.
**	-: A "-" sign specifies left adjusment of the output.
**	+: A "+" character specifies that there should always be a sign placed
**	before the number when using signed formats.
**	_: A space specifies that a blank should be left before before a positive
**	number for a signed format. A "+" overrides a space if both are used.
*/

static void	parse_length_modifier(t_bag *bag, char **format,
		char **length_modifiers)
{
	char	*format_pointer;
	char	*copy;
	int		i;

	format_pointer = *format;
	copy = ft_strdup(format_pointer);
	i = 0;
	while (copy[i] && !in_format_conversions(copy[i]))
		i++;
	copy[i] = '\0';
	if (in_length_modifiers(length_modifiers, copy))
	{
		bag->length_modifier = ft_strdup(copy);
		free(copy);
		*format = &(*format)[i];
	}
}

// t_bag return type is for unit_tests in main.c with handle_percent only
//t_bag		*handle_percent(char **format, va_list args, int *i)
void		handle_percent(char **format, va_list args, int *i)
{
	char	**length_modifiers;
	char	*format_pointer;
	t_bag	*bag;

	format_pointer = ++(*format);
	length_modifiers = set_length_modifiers_array();
	bag = malloc(sizeof(t_bag));
	initialize_t_bag_variables(bag);
	while (in_flags(bag, *format_pointer) && set_flags(bag, *format_pointer))
		format_pointer++;
	if (in_minimum_field_width(*format_pointer))
		bag->width = ft_atoi(format_pointer);
	while (in_minimum_field_width(*format_pointer))
		format_pointer++;
	if (*format_pointer == '.' && (bag->period = 1) && format_pointer++)
		if (in_precision(*format_pointer))
		{
			bag->precision = ft_atoi(format_pointer);
			while (in_precision(*format_pointer))
				format_pointer++;
		}
	parse_length_modifier(bag, &format_pointer, length_modifiers);
	if (in_format_conversions(*format_pointer))
		bag->format_conversion = *format_pointer++;
	print_format_conversion(bag, args, i);
	*format = format_pointer;
//	return (bag);
}
