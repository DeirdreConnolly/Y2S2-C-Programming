
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#define SIZE_STR 100
#define NUM_WORDS 10


//--------------------------------------//
//	main								//	
//--------------------------------------//
int main() {

	//------------- 1 --------------// 
	printf("\n---1. Use of strchr---\n");

	char a[] = "This is it";
	char* b = NULL;

	b = strchr(a, ' ');
	printf("%s\n", b);

	b = strchr(a, 'Z');
	printf("%s\n", b);

	//So, as we can see, it returns a pointer to the index of the array with the first appearance of the pattern

	//------------- 2 --------------// 
	printf("\n---2. Use of strstr---\n");

	b = strstr(a, "is");
	printf("%s\n", b);

	b = strstr(a, "Monday");
	printf("%s\n", b);

	return 0;

}






