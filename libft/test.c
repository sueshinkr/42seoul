#include <stdio.h>

int main(void)
{
	char a[] = {'a', 'b'};
	char b[] = {'1', '2', '3'};
	const char *p ="!!!!!";
	
	
	
	b = '!';
	printf("%c\n", b[0]);
	printf("%s\n", b);
	
	p = &a[0];
	printf("%c\n", *p);
	p = &a[1];
	printf("%c\n", *p);
	// *p = 'c';            // error: read-only variable is not assignable
	a[1] = 'd';
	printf("%c\n", *p);

	return 0;
}
