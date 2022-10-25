
#include <stdio.h>
#include <stdlib.h>

int* my_function1() {
	int a[3] = { 10, 20, 30 };
	return a;
}

int* my_function2() {
	int* a = (int*)malloc(3 * sizeof(int));
	a[0] = 10;
	a[1] = 20;
	a[2] = 30;
	return a;
}

//--------------------------------------//
//	main								//	
//--------------------------------------//

int main() {

	int* p = my_function1();

	printf("%d\n", p[1]);

	p = my_function2();
	printf("%d\n", p[1]);

	return 0;

}

