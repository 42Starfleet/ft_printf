#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"

void test_printfd()
{
	int n;
	int s;
	int test;

	s = 0;
	//n = ft_printf("%d\n", 0);
	//printf("result: %d\n", n);

//	n = ft_printf("%#d\n", 1);
//	printf("Number sign: %#d\n", 1);

	/*printf("------------------\n");
	printf("0 flag with no min width\n");
	printf("EXPECT: '%0d'\n", 45);
	ft_printf("RESULT: '%0d'\n", 45);
	printf("------------------\n");
	printf("'0' flag with min width > num width\n");
	n = printf("EXPECT: '%04d', ", 22);
	printf("R: %d\n", n);
	s= ft_printf("ACTUAL: '%04d', ", 22);
	printf("R: %d\n", s);
	printf("------------------\n");
	printf("'-' flag with no min width\n");
	test = 33;
	printf("EXPECT: \'%-d\', R: %zu\n", test, ft_strlen(ft_itoa(test)));
	ft_printf("ACTUAL: \'");*/
	test = 33;
	ft_putstr("print 33: ");
	s = ft_printf("%d", test);
	//printf("# of printed: %d\n", s); 
}
