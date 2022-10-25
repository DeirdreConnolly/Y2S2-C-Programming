
#include <stdio.h>

void swap_1(int* a, int* b) {
	int tmp = (*a);
	(*a) = (*b);
	(*b) = tmp;
}

void swap_2(int** a, int** b) {
	int* tmp = (*a);
	(*a) = (*b);
	(*b) = tmp;
}

int main() {
	int i = 2;
	int j = 3;
	int* pi = &i;
	int* pj = &j;
	int** ppi = &pi;
	int** ppj = &pj;

	//1. Swap i and j by swapping their values
	swap_1(pi, pj);
	printf("i value = %d\n", i);
	printf("j value = %d\n", j);
	printf("pi value-at-address = %d\n", *pi);
	printf("pj value-at-address = %d\n", *pj);

	//2. Swap i and j by swapping the values of the pointers pi and pj pointing at them
	swap_2(ppi, ppj);
	printf("i value = %d\n", i);
	printf("j value = %d\n", j);
	printf("pi value-at-address = %d\n", *pi);
	printf("pj value-at-address = %d\n", *pj);

	//3. Modify i by: (1) Using directly i. (2) Using its pointer pi. (3) Using its pointer to pointer ppi
	i = 10;
	printf("i value = %d\n", i);
	(*pj) = 20;
	printf("i value = %d\n", i);
	(**ppj) = 30;
	printf("i value = %d\n", i);

	return 0;
}












