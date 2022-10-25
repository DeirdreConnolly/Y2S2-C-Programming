
#include <stdio.h>
#include <stdlib.h>

//--------------------------------------//
//	fibonacci							//
//--------------------------------------//
int* fibonacci(int* n) {
	//We reserve space for the variable we are going to return.
	int* val = (int*)malloc(1 * sizeof(int));

	if ((*n) == 0) {
		(*val) = 0;
	}
	else if ((*n) == 1) {
		(*val) = 1;
	}
	else {
		//We reserve space for the variables n1 and n2 we are going to use in the recursive call
		int* n1 = (int*)malloc(1 * sizeof(int));
		(*n1) = (*n) - 1;
		int* n2 = (int*)malloc(1 * sizeof(int));
		(*n2) = (*n) - 2;

		//We gather in two pointers the results collected from fibonnaci(n1) and fibonacci(n2) to collect our result
		int* res1 = fibonacci(n1);
		int* res2 = fibonacci(n2);
		(*val) = (*res1) + (*res2);

		//We can free n1 and n2, as we will no longer need them.
		free(n1);
		free(n2);
		free(res1);
		free(res2);
	}

	return val;
}

//--------------------------------------//
//	main								//
//--------------------------------------//
int main() {
	//We reserve space for our variable i
	int* i = (int*)malloc(1 * sizeof(int));
	(*i) = 3;

	//We solve fibonnacci of i
	int* res = fibonacci(i);

	//We print the result
	printf("The value of the 3th fibonacci serie is %d\n", (*res));

	//We free the memory for i and for the fibonacci result. 
	free(res);
	free(i);

	return 0;
}







