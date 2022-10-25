
/*
- What is the output of this program?
*/

#include <stdio.h>

void my_function(){
	static i = 0;
	printf("val i = %d\n", i);
	i++;
}

int main(){
	my_function(); 
	my_function(); 
	return 0;
}





