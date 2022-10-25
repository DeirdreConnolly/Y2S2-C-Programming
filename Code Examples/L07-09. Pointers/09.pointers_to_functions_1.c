
#include <stdio.h>

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
//	FUNCTION main 
//------------------------------------
int main(int argc, char* argv[]) {
	//1. We declare my pointer variable
	funcptr f_ptr = NULL;;
	boolean mode = True;

	if (mode == False)
		f_ptr = &add_one;
	else
		f_ptr = &add_two;

	//2. We declare the variable we want to use
	int myVar = 3;
	int res = (*f_ptr)(myVar);

	printf("%d\n", res);

	return 0;
}



