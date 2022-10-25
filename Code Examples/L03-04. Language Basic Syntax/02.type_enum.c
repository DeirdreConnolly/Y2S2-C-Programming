
#include <stdio.h>

enum week { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
enum Bool { False, True };

int main() {
	enum Bool b = False;
	printf("val = %d\n", b);
	b = True;
	printf("val = %d\n", b);

	return 0;
}





