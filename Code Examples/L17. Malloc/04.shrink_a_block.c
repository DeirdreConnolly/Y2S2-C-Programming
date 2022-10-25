
#include <stdio.h>
#include <stdlib.h>

//--------------------------------------//
//	main								//
//--------------------------------------//
int main() {

	//------------- 1 ---------------//
	printf("BLOCK 1: RESERVE MEMORY \n");

	//1.1. We reserve space for our n variables and initialise them.
	int* a = (int*)malloc(sizeof(int) * 4);

	for (int i = 0; i < 4; i++) 
		a[i] = i;
	
	int* b = (int*)realloc(a, sizeof(int) * 3);

	int* c = (int*)malloc(sizeof(int) * 1);
	c[0] = 10;

	for (int i = 0; i < 4; i++) {
		printf("&a[%d] = %p\n", i, &a[i]);
		printf("a[%d] = %d\n", i, a[i]);
	}

	printf("&c[%d] = %p\n", 0, &c[0]);
	printf("c[%d] = %d\n", 0, c[0]);

	return 0;

}

