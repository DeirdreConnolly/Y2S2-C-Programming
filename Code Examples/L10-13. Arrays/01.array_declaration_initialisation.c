
#include <stdio.h>
#include <stdlib.h>

int main() {

	//1. Stack declaration
	//1.1. Declaration + initialisation
	int a[3] = { 10, 20, 30 };

	//1.2. Declaration + initialisation separately
	int b[3];
	for (int i = 0; i < 3; i++)
		b[i] = 10 * (i + 1);

	//1.3. Surprising value and address of 'a'
	printf("a address = %p\n", &a);
	printf("a value = %p\n", a);
	printf("a[0] address = %p\n", &a[0]);
	printf("a[0] value = %d\n", a[0]);
	printf("a[1] address = %p\n", &a[1]);
	printf("a[1] value = %d\n", a[1]);

	//2. Data Area declaration
	const int c[3] = { 10, 20, 30 };
	printf("c address = %p\n", &c);
	printf("c value = %p\n", c);
	//c[1] = 40; //--> Compilation error

	//3. Heap Area declaration
	//3.1. Declaration with malloc
	int* d = (int*)malloc(3 * sizeof(int));
	printf("d address = %p\n", &d);
	printf("d value = %p\n", d);

	//3.2. Initialisation with pointer notation
	*(d + 0) = 10;
	*(d + 1) = 20;
	*(d + 2) = 30;

	//3.3. Initialisation with array notation
	d[0] = 10;
	d[1] = 20;
	d[2] = 30;

	return 0;
}
