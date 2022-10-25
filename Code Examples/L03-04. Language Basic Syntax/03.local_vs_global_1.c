
/*
Can we use the global variable 'a' within the function?
*/

#include <stdio.h>

int a = 8;

void my_function(){
	int i = 0;
	while (i < a){
		printf("val = %d\n", i);
		i++;
	}
}

int main(){
	my_function(); 
	return 0;
}





