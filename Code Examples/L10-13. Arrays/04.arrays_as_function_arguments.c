
#include <stdio.h>
#include <stdlib.h>

//--------------------------------------//
//	functions							//	
//--------------------------------------//

void my_function1(int arg[], int size) {
	arg[1] = 1;
}

void my_function2(int arg[], int size) {
	*(arg + 1) = 2;
}

void my_function3(int* arg, int size) {
	arg[1] = 3;
}

void my_function4(int* arg, int size) {
	*(arg + 1) = 4;
}

void my_function5(int arg[3]) {
	arg[1] = 5;
}

void my_function6(int arg[3]) {
	*(arg + 1) = 6;
}


//--------------------------------------//
//	main								//	
//--------------------------------------//

int main() {

	int a[3] = { 10, 20, 30 };
	printf("%d\n", a[1]);

	my_function1(a, 3);
	printf("%d\n", a[1]);

	my_function2(a, 3);
	printf("%d\n", a[1]);

	my_function3(a, 3);
	printf("%d\n", a[1]);

	my_function4(a, 3);
	printf("%d\n", a[1]);

	my_function5(a);
	printf("%d\n", a[1]);

	my_function6(a);
	printf("%d\n", a[1]);

	return 0;

}

