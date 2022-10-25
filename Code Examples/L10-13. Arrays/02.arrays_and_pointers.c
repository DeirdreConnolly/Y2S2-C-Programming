
#include <stdio.h>
#include <stdlib.h>

int main() {

	int a[3] = { 10, 20, 30 };

	//1. 'a' is not a truly pointer, but it acts as a const pointer to &a[0]
	printf("a address = %p\n", &a);
	printf("a value = %p\n", a);
	printf("a[0] address = %p\n", &a[0]);
	printf("a[0] value = %d\n", a[0]);

	//2. Other pointers can be assigned to 'a', but as 'a' is const it cannot be assigned to other pointers.
	int* p = a;
	//a = p; //--> Compilation error

	//3. Use pointer maths on 'a' or p to access/modify the array subscripts.	
	//We can use either pointer notation or array notation
	*(a + 1) = 25;
	a[2] = 35;
	printf("a[1] = %d\n", a[1]);
	printf("a[2] = %d\n", *(a + 2));

	*(p + 1) = 20;
	p[2] = 30;
	printf("a[1] = %d\n", p[1]);
	printf("a[2] = %d\n", *(p + 2));

	return 0;
}

