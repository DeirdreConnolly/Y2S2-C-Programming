#include <stdio.h>

int main() {
	int n = 4; 
	int res = 1;
	int aux = 1;
	while (n > aux) {
		aux = aux + 1;
		int a = res;
		int b = aux - 1;
		while (b > 0) {
			res = res + a;
			b = b - 1;
		}
	}
	printf("%d\n", res);
	return 0;
}

