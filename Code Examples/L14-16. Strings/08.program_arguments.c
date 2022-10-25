
#include <stdio.h>
#include <stdlib.h>

//08.program_arguments.exe file.txt 300
int main(int argc, char* argv[]) {

	printf("argc = %d\n", argc);
	printf("argv[0] = %s\n", argv[0]);
	printf("argv[1] = %s\n", argv[1]);
	printf("argv[2] = %s\n", argv[2]);

	int i = atoi(argv[2]);
	printf("The new integer i = %d\n", i);

	return 0;
}





