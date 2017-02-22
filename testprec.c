#include "includes/fractol.h"

int		main(void)
{
	long double a;
	long double b;

	a = 100000;
	b = 10000;
	while (a != a + b)
	{
		a = a + b;
		b = b / 10;
		printf("a = %LF", a); 
	}
	return (0);
}