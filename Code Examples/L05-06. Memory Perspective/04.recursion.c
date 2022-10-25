#include <stdio.h>

int fibonacci(int n) {
	int val = 0;
	printf("n address = %p\n", &n);	
	printf("n value = %d\n", n);
	printf("val address = %p\n", &val);
	printf("val value = %d\n", val);

	if (n == 0) {
		val = 0;
	}
	else if (n == 1) {
		val = 1;
	}
	else {
		val = fibonacci(n - 1) + fibonacci(n - 2);
	}

	return val;
}


int main() {
	int i = 3;
	printf("The value of the 3th fibonacci serie is %d\n", fibonacci(i));
	return 0;
}







