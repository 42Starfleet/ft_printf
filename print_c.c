#include "ft_printf.h"

/*
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

void	print_c(t_bag *bag, va_list args, int *i)
{
	char pad_character;
	char c;
	char *str;
	wchar_t c_wide;

	pad_character = bag->zero ? '0' : ' ';
	if (bag->format_conversion  == 'c')
		c = (char)va_arg(args, void *);
	else if (bag->format_conversion == 'C')
		c_wide = (wchar_t)va_arg(args, void *);
	str = malloc(sizeof(char) * 2);
	if (c)
		str[0] = c;
	else if (c_wide)
		str[0] = c_wide;
	else
	{
		while (--bag->width > 0)
		{
			ft_putchar(' ');
			(*i)++;
		}
		ft_putchar(0);
		*i += 1;
		return ;
	}
	str[1] = '\0';
	if (bag->minus && bag->width > 0)
		str = pad_right(str, bag->width, pad_character);
	else if (bag->width > 0)
		str = pad_left(str, bag->width, pad_character);
	*i += ft_strlen(str);
	ft_putstr(str);
}
