
#include <stdio.h>
#include <stdlib.h>

//--------------------------------------//
//	main								//	
//--------------------------------------//

int main() {

	//---------------------//
	//   1. Fixed Size     //
	//---------------------//
	//1.1. Stack arrays need to be declared with constant size.
	int a[3] = { 10, 20, 30 };

	//1.2. If we try to declare an array with variable size it will trigger a compilation error.
	int x = a[0];
	//int b[x];  //--> Compilation error.The value of x is unknown in compilation time.
	//	for (int i = 0; i < x; i++)          
	//		b[i] = 10 + i;

	//1.3. Thus, the only way to declare arrays of variable size is to do so in the heap
	int* c = (int*)malloc(x * sizeof(int));
	for (int i = 0; i < x; i++)
		c[i] = 10 + i;

	//-------------------------------------------------------//
	//   2. Set all the elements of the array at a time      //
	//-------------------------------------------------------//

	//2.1. We cannot assign an already existing array to a bunch of new values.
	//a = { 15, 25, 35 };  //--> Compilation error

	//--------------------------------------------//
	//   3. Arrays do not support assignment      //
	//--------------------------------------------//
	//3.1. You ---cannot--- declare and initialise an array with another array
	//int b[3] = a; //--> Compilation error


	//3.2. You ---cannot--- assign an entire existing array to the values of another array
	int b[3] = { 15, 25, 35 };
	//b = a; //--> Compilation error

	//-------------------------------------------------------//
	//   4. You can access to elements out of the range of   //
	//      the array with no compilation nor runtime error  //
	//-------------------------------------------------------//
	printf("\n--- 4. You can access to elements out of the range of the array ---\n");

	printf("a[1] = %d\n", a[1]);
	a[1] = a[79];  //--> No compilation error.
	printf("a[1] = %d\n", a[1]);
	printf("a[41] = %d\n", a[41]);
	a[41] = a[79]; //--> No compilation error.
	printf("a[41] = %d\n", a[41]);

	return 0;

}

