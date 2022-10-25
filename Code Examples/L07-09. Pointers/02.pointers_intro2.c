
#include <stdio.h>

int main() {
	int val = 1;
	int* ptr = &val;

	printf("ptr value = %p\n", ptr); //Value written in the envelope. Address of the house. 
	printf("address of &ptr = %p\n", &ptr); //The proper envelope address. 
											//The envelope is produced in a house as well :)
	printf("value at address of ptr = %d\n", *ptr); //People living at the house. 

	//We can use as many address and value-at-address operators as we want.
	printf("val1 = %d\n", *(&val)); 
	printf("val2 = %d\n", *(&(*(&val)))); 

	return 0;
}









