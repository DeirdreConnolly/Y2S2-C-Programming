
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

//--------------------------------------//
//	main								//	
//--------------------------------------//

int main() {

	//------------- 1 --------------// 
	printf("\n--- 1. String Init ---\n");

	char b[] = "abcd";
	char a[] = "1234";
	printf("Address of b = %p; Value of b = %s; Length of b = %d\n", &b[0], b, strlen(b));
	printf("Address of a = %p; Value of a = %s; Length of a = %d\n", &a[0], a, strlen(a));

	//------------- 2 --------------// 
	printf("\n--- 2. Use of strcpy ---\n");

	strcpy(b, "Today is Monday 2th");

	printf("Address of b = %p; Value of b = %s; Length of b = %d\n", &b[0], b, strlen(b));
	printf("Address of a = %p; Value of a = %s; Length of a = %d\n", &a[0], a, strlen(a));

	return 0;

}

