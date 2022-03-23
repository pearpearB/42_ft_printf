#include "ft_printf.h"
#include <stdio.h>


int main ()
{
	printf("start!\n");
	int res1 = printf("real printf: Hello, %s %d %i %u %X\n", "World!", 42, 42, 8282, 10);
	int res2 = ft_printf("my printf: Hello, %s %d %i %u %X\n", "World!", 42, 42, 8282, 10); // my printf: Hello, World! 42 42 8282 [1]    95118 bus error  ./a.out

	printf("real: %d\n", res1);
	printf("my: %d\n", res2);

	return 0;
}