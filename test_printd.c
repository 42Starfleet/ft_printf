#include <stdio.h>
#include "ft_printf.h"

void test_printfd()
{
	int n;
	int s;

	n = ft_printf("%d\n", 0);
	printf("result: %d\n", n);

//	n = ft_printf("%#d\n", 1);
//	printf("Number sign: %#d\n", 1);

	printf("0 flag with no min width\n");
	printf("EXPECTED: '%0d'\n", 45);
	ft_printf("RESULT: '%0d'\n", 45);
	printf("0 flag with min width > num width\n");
	n = printf("EXPECTED: '%04d'\n", 22);
	s= ft_printf("ACTUAL: '%04d'\n", 22);
	printf("EXPECTED return: %d\n", n);
	printf("ACTUAL return: %d\n", s); 
	n = ft_printf("Width: %3.3d\n", 2);
	printf("Width: %5.4d\n", 235);
	printf("Width: %04d\n", 245);
	printf("Width: %4d\n", 267);

}
