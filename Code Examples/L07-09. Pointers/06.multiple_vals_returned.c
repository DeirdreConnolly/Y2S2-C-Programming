
/*
- What is the output of this program?
- How would it change if we use new_add_3 instead?
*/

#include <stdio.h>

int my_function(int* pi, char* pc, float* pf) {
	(*pi) = 3;
	(*pc) = 'b';
	(*pf) = (*pf) + 5.0;

	return 7;
}


int main() {
	int i = 2;
	char c = 'a';
	float f = 3.5;

	int k = my_function(&i, &c, &f);
	printf("i = %d\n", i);
	printf("c = %c\n", c);
	printf("f = %f\n", f);
	printf("k = %d\n", k);

	return 0;
}












