
#include <stdio.h>

void my_function(int n) {
	static int i = 0;
	printf("--------------\n");
	printf("i address = %p\n", &i);
	printf("i val = %d\n", i);
	printf("n address = %p\n", &n);
	printf("n val = %d\n", n);
	i = i + n;
}

void extra(int x) {
	my_function(x);
}

int main() {
	int j = 1;
	my_function(j);
	extra(j);

	return 0;
}





