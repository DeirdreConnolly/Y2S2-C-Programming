
#include <stdio.h>


int main() {
	int* ptr;
	int val = 1;
	ptr = &val;
	int deref = *ptr;
	printf("%d\n", deref);

	//But, what would it happen if we ask for the addresses of val and deref?

	//What's the size of ptr?

	return 0;
}







