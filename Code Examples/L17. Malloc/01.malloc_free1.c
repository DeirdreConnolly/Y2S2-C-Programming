
#include <stdio.h>
#include <stdlib.h>

//--------------------------------------//
//	main								//
//--------------------------------------//
int main() {

	int n = 4;
	int accum = 1;

	//------------- 1 ---------------//
	printf("BLOCK 1: RESERVE MEMORY \n");

	//1.1. We reserve space for our n variables and initialise them.
	int* a = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		a[i] = accum;
		accum = accum * 2;
	}

	//1.2. We see that we can access to the memory reserved from 
	//any pointer: The pointer returned or any other pointer we want to make pointing there.
	int* p = a;
	for (int i = 0; i < n; i++) {
		printf("&a[%d] = %p\n", i, &p[i]);
		printf("a[%d] = %d\n", i, p[i]);
	}

	//------------- 2 ---------------//
	printf("BLOCK 2: FREE THE MEMORY \n");

	//2.1. We free the memory block previously reserved.
	free(p);
	p = NULL;

	//2.2. We allocate new memory for 'b', which is then using the space of 'a' that was just free. 
	int* b = (int*)malloc(n * sizeof(int));

	//2.3. We initialise and print 'b'
	for (int i = 0; i < n; i++) {
		b[i] = accum - 1;
		accum = accum / 2;
	}

	for (int i = 0; i < n; i++) {
		printf("&b[%d] = %p\n", i, &b[i]);
		printf("b[%d] = %d\n", i, b[i]);
	}

	return 0;

}

