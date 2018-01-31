#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"

void test_printfd()
{
	int n;
	int s;
	int test;

	s = ft_printf("'@moulitest: %.d %.0d'", 0, 0);
	ft_printf("\nreturn: %d\n", s);
	sleep(1);
	printf("@moulitest: %.d %.0d", 0, 0);
	/*printf("0 flag with min width > num width\n");
	n = printf("EXPECTED: '%04d'\n", 22);
	s= ft_printf("ACTUAL: '%04d'\n", 22);
	printf("EXPECTED return: %d\n", n);
	printf("ACTUAL return: %d\n", s); 
	n = ft_printf("Width: %3.3d\n", 2);
	printf("Width: %5.4d\n", 235);
	printf("Width: %04d\n", 245);
	printf("Width: %4d\n", 267);*/

	//	n = ft_printf("%x\n", 0);
//	printf("result: %x\n", n);

//	n = ft_printf("%#d\n", 1);
//	printf("Number sign: %#d\n", 1);

	/*int len2 = 0;
	len2 = ft_printf("%x\t%X\t%#x\t%#X this is s1\n", -10, 255, 255, 255);
	n = printf("%x\t%X\t%#x\t%#X this is s2\n", -10, 255, 255, 255);
	printf("n -> %d\tn2 -> %d\n", n, len2);
	ft_printf("TESTING: %#x\n", 123456789123456789);*/
}
