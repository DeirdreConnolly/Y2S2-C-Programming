
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
	//EXTRA: Now we also reserve space for another n variables. 
	int* b = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		a[i] = accum;
		accum = accum * 2;
		printf("&a[%d] = %p\n", i, &a[i]);
		printf("a[%d] = %d\n", i, a[i]);
	}

	for (int i = 0; i < n; i++) {
		b[i] = accum - 1;
		accum = accum / 2;
		printf("&b[%d] = %p\n", i, &b[i]);
		printf("b[%d] = %d\n", i, b[i]);
	}

	//------------- 2 ---------------//
	printf("\nBLOCK 2: REALLOCATE THE MEMORY BLOCK 'a' \n");

	//2.1. We turn the block 'a' into big enough that it does not fit in the memory addresses it had before. 
	//We see how realloc finds a different place in the virtual memory so as to reallocate the block with the new extended size. 
	int* new_a = (int*)realloc(a, sizeof(int) * (5 * n));

	//2.2. If realloc manages to assign a new space...
	if (new_a != NULL) {
		//2.2.1. We make 'a' to point to its new allocated space.
		a = new_a;

		//2.2.2. We check that, for the positions of 'a' that were there before the realloc, 
		//they still maintain the value they had before reallocating 'a' to its new extended size. 
		for (int i = 0; i < n; i++) {
			printf("&a[%d] = %p\n", i, &a[i]);
			printf("a[%d] = %d\n", i, a[i]);
		}

		//2.2.3. We initialise and print the values for the new extended 'a'.
		for (int i = n; i < (5 * n); i++) {
			a[i] = i;
			printf("&a[%d] = %p\n", i, &a[i]);
			printf("a[%d] = %d\n", i, a[i]);
		}

		//2.2.4. To check that the block of memory 'a' was allocated before the realloc has effectively freed, 
		//we create a new array 'c' and see how it takes the space 'a' left when reallocated to fit its extended new size.
		int* c = (int*)malloc(sizeof(int) * n);

		for (int i = 0; i < n; i++) {
			c[i] = i;
			printf("&c[%d] = %p\n", i, &c[i]);
			printf("c[%d] = %d\n", i, c[i]);
		}

	}

	return 0;

}

