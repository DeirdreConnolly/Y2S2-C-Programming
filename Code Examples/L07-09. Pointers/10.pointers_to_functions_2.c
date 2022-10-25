
#include <stdio.h>
#include <stdlib.h>

typedef int(*funcptr)();
enum Bool { False, True };
typedef enum Bool boolean;

//------------------------------------
//	FUNCTION add_one 
//------------------------------------
int add_one(int val) {
	int res = val + 1;
	return res;
}

//------------------------------------
//	FUNCTION add_two 
//------------------------------------
int add_two(int val) {
	int res = val + 2;
	return res;
}

//------------------------------------
//	FUNCTION map 
//------------------------------------
int* map(funcptr my_f_ptr, int* myArray, int size) {
	//1. We use malloc to create the returned array
	int* res = (int*)malloc(size * sizeof(int));

	//2. We apply the map operation to each element of the array
	for (int i = 0; i < size; i++)
		res[i] = (*my_f_ptr)(myArray[i]);

	//3. We return the result
	return res;
}

//------------------------------------
//	FUNCTION main 
//------------------------------------
int main(int argc, char* argv[]) {
	//1. We declare my pointer variable
	funcptr f_ptr;
	boolean mode = True;

	if (mode == False)
		f_ptr = &add_one;
	else
		f_ptr = &add_two;

	//2. We declare the variable we want to use
	int myArray[3] = { 1,2,3 };
	int* res = map(f_ptr, myArray, 3);

	printf("{ %d, %d, %d }\n", res[0], res[1], res[2]);

	return 0;
}
