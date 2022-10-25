
#include <stdio.h>
#include <stdlib.h>

//--------------------------------------//
//	functions							//	
//--------------------------------------//

//void my_function1(int v[][], int size1, int size2) {  //--> Compilation error
//	v[1][1] = 18;
//}

void my_function2(int v[][3], int size1) {
	v[1][1] = 18;
}

void my_function3(int** v, int size1, int size2, int size3) {
	v[1][1] = 18;
}


//--------------------------------------//
//	main								//	
//--------------------------------------//

int main() {

	//1. Declaration and initialisation of the array
	int a[2][3] = { 1,2,3,4,5,6 };
	printf("Adresses of a\n");
	printf("&a[0][0] = %p\n", &a[0][0]);
	printf("a[0][0] = %d\n", a[0][0]);
	printf("&a[0][1] = %p\n", &a[0][1]);
	printf("a[0][1] = %d\n", a[0][1]);
	printf("&a[0][2] = %p\n", &a[0][2]);
	printf("a[0][2] = %d\n", a[0][2]);
	printf("&a[1][0] = %p\n", &a[1][0]);
	printf("a[1][0] = %d\n", a[1][0]);
	printf("&a[1][1] = %p\n", &a[1][1]);
	printf("a[1][1] = %d\n", a[1][1]);
	printf("&a[1][2] = %p\n", &a[1][2]);
	printf("a[1][2] = %d\n", a[1][2]);

	//2. Pointer maths for the array 
	printf("\nPointer Maths\n");
	printf("Address of a = %p\n", a);
	printf("Address of (a + 1) = %p\n", (a + 1));

	printf("Address of a[0] = %p\n", a[0]);
	printf("Address of (a[0] + 1) = %p\n", (a[0] + 1));

	printf("Address of a[1] = %p\n", a[1]);
	printf("Address of (a[1] + 1) = %p\n", (a[1] + 1));

	//3. We call to a function with a
	my_function2(a, 2);

	//4. We define a new array. 
	int* b[2];
	int v[3] = { 1,2,3 };
	int w[5] = { 4,5,6,7,8 };
	b[0] = v;
	b[1] = w;

	printf("\nAdresses of b\n");
	printf("Address of b[0] = %p\n", &b[0]);
	printf("Value of b[0] = %p\n", b[0]);
	printf("Address of b[1] = %p\n", &b[1]);
	printf("Value of b[1] = %p\n", b[1]);

	printf("\nAdresses of v\n");
	printf("Address of v[0] = %p\n", b[0]);
	printf("Value of v[0] = %d\n", *b[0]);
	printf("Address of v[1] = %p\n", (b[0] + 1));
	printf("Value of v[1] = %d\n", *(b[0] + 1));
	printf("Address of v[2] = %p\n", (b[0] + 2));
	printf("Value of v[2] = %d\n", *(b[0] + 2));

	printf("\nAdresses of w\n");
	printf("Address of w[0] = %p\n", b[1]);
	printf("Value of w[0] = %d\n", *b[1]);
	printf("Address of w[1] = %p\n", (b[1] + 1));
	printf("Address of w[1] = %d\n", *(b[1] + 1));
	printf("Address of w[2] = %p\n", (b[1] + 2));
	printf("Address of w[2] = %d\n", *(b[1] + 2));
	printf("Address of w[3] = %p\n", (b[1] + 3));
	printf("Address of w[3] = %d\n", *(b[1] + 3));
	printf("Address of w[4] = %p\n", (b[1] + 4));
	printf("Address of w[4] = %d\n", *(b[1] + 4));

	return 0;

}

