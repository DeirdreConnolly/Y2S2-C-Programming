#include <stdio.h>

int main() {
	int n = 6;
	int d = 3;

	int compareTo = 1;
	int index = 0;
	int res = 0;

	while (d > index) {
		int aux = (n & compareTo);
		res = res + aux;
		n = n >> 1;
		index = index + 1;
	}
	printf("%d\n", res);
	return 0;
}

