

/*
- How many calls are done to the function fibonacci?
- How many variables are created during the execution of the program?
*/

#include <stdio.h>

int fibonacci(int n) {
	int val = 0;

	if (n == 0) {
		val = 0;
	}
	else if (n == 1) {
		val = 1;
	}
	else {
		int n1 = n - 1;
		int n2 = n - 2;

		int res1 = fibonacci(n1);
		int res2 = fibonacci(n2);

		val = res1 + res2;
	}

	return val;
}


int main() {
	int x = fibonacci(3);

	printf("The value of the 3th fibonacci serie is %d\n", x);

	return 0;
}









