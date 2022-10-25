#include <stdio.h>

int main() {
	int n = 2;
	int a[2] = { 5, 4 };

	int index = 0;
	int res = 0;
	while (n > index) {
		int aux = a[0 + index];
		res = res + aux;
		index = index + 1;
	}
	printf("%d\n", res);
	return 0;
}

