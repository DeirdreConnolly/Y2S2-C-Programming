
#include <stdio.h>

void my_function(int n, int* q) {
	n = 10;
	(*q) = 20;
	q = q + 1;
}

int main() {
	int i = 3;
	int j = 4;
	int* p = &i;

	my_function(i, p);

	printf("i address = %p\n", &i);
	printf("i value = %d\n", i);
	printf("j address = %p\n", &j);
	printf("j value = %d\n", j);
	printf("p value = %p\n", p);

	return 0;
}
