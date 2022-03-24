#include "ft_printf.h"
#include <stdio.h>


int main ()
{
	char *pointer = "10";
	printf("start!\n");
	int res1 = printf("real printf: %p\n", pointer);
	int res2 = ft_printf("mymy printf: %p\n", pointer); 

	printf("real: %d\n", res1);
	printf("my: %d\n", res2);

	return 0;
}