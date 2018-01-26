/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroshiusui <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 09:42:50 by hiroshius         #+#    #+#             */
/*   Updated: 2018/01/26 09:42:52 by hiroshius        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Tutorial function on how to use va_list for functions with variable arguments.

void foo(char *fmt, ...)
{
	va_list ap, ap2;
	int d;
	char c, *s;

	char *duplicate = strdup(fmt);
	va_copy(ap2, ap);
	while (*fmt)
	{
		switch(*fmt++) {
			case 's':                       /* string */
				s = va_arg(ap, char *);
				printf("string %s\n", s);
				break;
			case 'd':                       /* int */
				d = va_arg(ap, int);
				printf("int %d\n", d);
				break;
			case 'c':                       /* char */
				/* Note: char is promoted to int. */
				c = va_arg(ap, int);
				printf("char %c\n", c);
				break;
		}
	}
	while (*duplicate)
	{
		switch(*duplicate++) {
			case 's':                       /* string */
				s = va_arg(ap2, char *);
				printf("string %s\n", s);
				break;
			case 'd':                       /* int */
				d = va_arg(ap2, int);
				printf("int %d\n", d);
				break;
			case 'c':                       /* char */
				/* Note: char is promoted to int. */
				c = va_arg(ap2, int);
				printf("char %c\n", c);
				break;
		}
		
	}
	va_end(ap);
}

int main()
{
	// Emoji test.
	//setlocale(LC_ALL,"");
    //printf("Let's go to the cantina and eat some %lc\n", 0x1F35D);

	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("***************************BEGIN UNIT TESTS******************************\n");
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");

	t_bag *bag = 0;
	char *format = 0;
	int	number_of_printed_characters = 0;
	int n = 0;
	va_list dummy;
	char *expected = 0;
	char *str = 0;
	char pad_character = 0;

	printf("***********************HANDLE_PERCENT PARSING TESTS***************************\n");
	printf("For these parsing tests to work, make sure to remember to set return type from \"void\" to \"t_bag *\" on function \"handle_percent\". Set it back to void when you are done.\n");

	/*
	format = "%+d";
	printf("%s\n", format);
	bag = handle_percent(&format, dummy, &number_of_printed_characters);
	expected = "1";
	printf("PLUS FLAG IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->plus, expected);
	printf("TYPE IS: %c, RESULT IS SUPPOSED TO BE: %s\n", bag->type, expected);
	printf("\n");

	format = "%-d";
	printf("%s\n", format);
	bag = handle_percent(&format, dummy, &number_of_printed_characters);
	expected = "1";
	printf("MINUS FLAG IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->minus, expected);
	printf("TYPE IS: %c, RESULT IS SUPPOSED TO BE: %s\n", bag->type, expected);
	printf("\n");

	format = "%-d";
	printf("%s\n", format);
	bag = handle_percent(&format, dummy, &number_of_printed_characters);
	expected = "d";
	printf("MINUS FLAG IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->minus, expected);
	printf("TYPE IS: %c, RESULT IS SUPPOSED TO BE: %s\n", bag->type, expected);
	printf("\n");

	format = "%+300.400Xd";
	printf("%s\n", format);
	bag = handle_percent(&format, dummy, &number_of_printed_characters);
	expected = "0";
	printf("MINUS FLAG IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->minus, expected);
	expected = "1";
	printf("PLUS FLAG IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->plus, expected);
	expected = "300";
	printf("MINIMUM FIELD WIDTH IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->width, expected);
	expected = "400";
	printf("PRECISION IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->precision, expected);
	expected = "X";
	printf("TYPE IS: %c, RESULT IS SUPPOSED TO BE: %s\n", bag->type, expected);
	expected = "d";
	printf("FORMAT_POINTER IS AT CHARACTER: %c, RESULT IS SUPPOSED TO BE: %s\n", *format, expected);
	printf("\n");

	format = "%.400Xd";
	printf("%s\n", format);
	bag = handle_percent(&format, dummy, &number_of_printed_characters);
	expected = "0";
	printf("MINUS FLAG IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->minus, expected);
	expected = "-1";
	printf("MINIMUM FIELD WIDTH IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->width, expected);
	expected = "400";
	printf("PRECISION IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->precision, expected);
	expected = "X";
	printf("TYPE IS: %c, RESULT IS SUPPOSED TO BE: %s\n", bag->type, expected);
	expected = "d";
	printf("FORMAT_POINTER IS AT CHARACTER: %c, RESULT IS SUPPOSED TO BE: %s\n", *format, expected);
	printf("\n");

	format = "%400Xd";
	printf("%s\n", format);
	bag = handle_percent(&format, dummy, &number_of_printed_characters);
	expected = "0";
	printf("MINUS FLAG IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->minus, expected);
	expected = "400";
	printf("MINIMUM FIELD WIDTH IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->width, expected);
	expected = "-1";
	printf("PRECISION IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->precision, expected);
	expected = "X";
	printf("TYPE IS: %c, RESULT IS SUPPOSED TO BE: %s\n", bag->type, expected);
	expected = "d";
	printf("FORMAT_POINTER IS AT CHARACTER: %c, RESULT IS SUPPOSED TO BE: %s\n", *format, expected);
	printf("\n");

	format = "%Dd";
	printf("%s\n", format);
	bag = handle_percent(&format, dummy, &number_of_printed_characters);
	expected = "0";
	printf("MINUS FLAG IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->minus, expected);
	expected = "-1";
	printf("MINIMUM FIELD WIDTH IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->width, expected);
	expected = "-1";
	printf("PRECISION IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->precision, expected);
	expected = "D";
	printf("TYPE IS: %c, RESULT IS SUPPOSED TO BE: %s\n", bag->type, expected);
	expected = "d";
	printf("FORMAT_POINTER IS AT CHARACTER: %c, RESULT IS SUPPOSED TO BE: %s\n", *format, expected);
	printf("\n");

	format = "%-03.5hhdHello";
	printf("%s\n", format);
	bag = handle_percent(&format, dummy, &number_of_printed_characters);
	expected = "1";
	printf("MINUS FLAG IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->minus, expected);
	expected = "0";
	printf("ZERO FLAG IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->zero, expected);
	expected = "3";
	printf("MINIMUM FIELD WIDTH IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->width, expected);
	expected = "5";
	printf("PRECISION IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->precision, expected);
	expected = "hh";
	printf("LENGTH_MODIFIER IS: %s, RESULT IS SUPPOSED TO BE: %s\n", bag->length_modifier, expected);
	expected = "d";
	printf("TYPE IS: %c, RESULT IS SUPPOSED TO BE: %s\n", bag->type, expected);
	expected = "H";
	printf("FORMAT_POINTER IS AT CHARACTER: %c, RESULT IS SUPPOSED TO BE: %s\n", *format, expected);
	printf("\n");

	format = "%03.5zdHello";
	printf("%s\n", format);
	bag = handle_percent(&format, dummy, &number_of_printed_characters);
	expected = "0";
	printf("MINUS FLAG IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->minus, expected);
	expected = "1";
	printf("ZERO FLAG IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->zero, expected);
	expected = "3";
	printf("MINIMUM FIELD WIDTH IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->width, expected);
	expected = "5";
	printf("PRECISION IS: %d, RESULT IS SUPPOSED TO BE: %s\n", bag->precision, expected);
	expected = "z";
	printf("LENGTH_MODIFIER IS: %s, RESULT IS SUPPOSED TO BE: %s\n", bag->length_modifier, expected);
	expected = "d";
	printf("TYPE IS: %c, RESULT IS SUPPOSED TO BE: %s\n", bag->type, expected);
	expected = "H";
	printf("FORMAT_POINTER IS AT CHARACTER: %c, RESULT IS SUPPOSED TO BE: %s\n", *format, expected);
	printf("\n");

	printf("***********************PAD_LEFT TESTS***************************\n");
	str = "TEST";
	n = 5;
	pad_character = ' ';
	expected = " TEST";
	printf("PAD_LEFT OF %d ON %s = \"%s\", EXPECTED: \"%s\"\n", n, str, pad_left(str, n, pad_character), expected);

	str = "100";
	n = 10;
	pad_character = '0';
	expected = "0000000100";
	printf("PAD_LEFT OF %d ON %s = \"%s\", EXPECTED: \"%s\"\n", n, str, pad_left(str, n, pad_character), expected);

	str = "100";
	n = 3;
	pad_character = '0';
	expected = "100";
	printf("PAD_LEFT OF %d ON %s = \"%s\", EXPECTED: \"%s\"\n", n, str, pad_left(str, n, pad_character), expected);

	printf("***********************PAD_RIGHT TESTS***************************\n");
	str = "TEST";
	n = 5;
	pad_character = '0';
	expected = "TEST0";
	printf("PAD_RIGHT OF %d ON %s = \"%s\", EXPECTED: \"%s\"\n", n, str, pad_right(str, n, pad_character), expected);

	str = "100";
	n = 10;
	pad_character = ' ';
	expected = "100       ";
	printf("PAD_RIGHT OF %d ON %s = \"%s\", EXPECTED: \"%s\"\n", n, str, pad_right(str, n, pad_character), expected);

	str = "100";
	n = 3;
	pad_character = '0';
	expected = "100";
	printf("PAD_RIGHT OF %d ON %s = \"%s\", EXPECTED: \"%s\"\n", n, str, pad_right(str, n, pad_character), expected);

	printf("***********************CUT_LEFT TESTS***************************\n");
	str = "100";
	n = 2;
	expected = "0";
	printf("CUT_LEFT OF %d ON %s = \"%s\", EXPECTED: \"%s\"\n", n, str, cut_left(str, n), expected);

	str = "100";
	n = 5;
	expected = "";
	printf("CUT_LEFT OF %d ON %s = \"%s\", EXPECTED: \"%s\"\n", n, str, cut_left(str, n), expected);

	printf("***********************CUT_RIGHT TESTS***************************\n");
	str = "100";
	n = 2;
	expected = "1";
	printf("CUT_RIGHT OF %d ON %s = \"%s\", EXPECTED: \"%s\"\n", n, str, cut_right(str, n), expected);

	str = "100";
	n = 5;
	expected = "";
	printf("CUT_RIGHT OF %d ON %s = \"%s\", EXPECTED: \"%s\"\n", n, str, cut_right(str, n), expected);
	*/
}
