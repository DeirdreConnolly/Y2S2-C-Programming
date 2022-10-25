
#include <stdio.h>

int main() {
	//Non-initialised Pointers
	int* non_init_pointer;
	printf("non_init_pointer address = %p\n", &non_init_pointer);
	printf("non_init_pointer value = %p\n", non_init_pointer); //Prints garbage
	//printf("non_init_pointer value-at-address = %d\n", *non_init_pointer); //--> Execution error. Access violation reading location (the garbage content the pointer has at the moment).

	//NULL Pointers
	int* null_pointer = NULL;
	printf("null_pointer address = %p\n", &null_pointer);
	printf("null_pointer value = %p\n", null_pointer);
	//printf("null_pointer value-at-address = %d\n", *null_pointer);//--> Execution error. Access violation reading location (the special position 0000).

	//Now initialised
	int i = 1;
	null_pointer = &i;
	printf("null_pointer address = %p\n", &null_pointer);
	printf("null_pointer value = %p\n", null_pointer);
	printf("null_pointer value-at-address = %d\n", *null_pointer);

	return 0;
}







