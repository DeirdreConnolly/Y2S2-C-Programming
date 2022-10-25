
#include <stdio.h>

int a = 8;

void my_function(){
	int i = 0;
	int a = 2;

	while (i < a){
		printf("val = %d\n", i);
		i++;
	}
	printf("local a = %d\n", a);
}

int main(){
	my_function(); 
	printf("global a = %d\n", a);
	return 0;
}





