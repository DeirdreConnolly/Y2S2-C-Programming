
#include <stdio.h>

int a = 3;

void my_function(int n) {
	int a = 2;

	printf("local 'a' value = %d\n", a);
	printf("local 'a' address = %p\n", &a);
	printf("local 'a' size = %d\n", sizeof(a));

	while (n < a)
		n = n + 1;
}

int main() {
	int i = 0;
	my_function(i);
	printf("global 'a' value = %d\n", a);
	printf("global 'a' address = %p\n", &a);
	printf("global 'a' size = %d\n", sizeof(a));

	return 0;
}

