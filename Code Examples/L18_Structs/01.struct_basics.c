

#include <stdio.h>
#include <stdlib.h>

//--------------------------------------//
//	Very basic struct					//	
//--------------------------------------//

struct static_fields {
	int i;
	char c;
	float f;
};

//--------------------------------------//
//	my_function							//	
//--------------------------------------//

struct static_fields my_function(struct static_fields s) {

	struct static_fields aux;
	aux.i = s.i + 3;
	if (s.c == 'b')
		aux.c = 'c';
	else
		aux.c = s.c;
	aux.f = s.f;

	return aux;
}

//--------------------------------------//
//	main								//	
//--------------------------------------//
int main(int argc, char* argv[]) {

	//----------------------------------------------------
	//1. See the struct definition and initialisation
	//----------------------------------------------------

	//1.1. Initialise a varaible straight away
	struct static_fields var1 = { 3, 'a', 5.0 };

	//1.2. Initialise a varaible field by field
	struct static_fields var2;
	var2.i = 4;
	var2.c = 'b';
	var2.f = (float) 10.2;

	//1.3. Initialise a variable by making it equal to other variable
	struct static_fields var3 = var2;

	//1.4. Print the info to see they are different.
	printf("\n--- BLOCK 1 ---\n");
	printf("--- var1 ---\n");
	printf("%p\n", &var1);

	printf("%p\n", &var1.i);
	printf("%d\n", var1.i);
	printf("%p\n", &var1.c);
	printf("%c\n", var1.c);
	printf("%p\n", &var1.f);
	printf("%f\n", var1.f);

	printf("--- var2 ---\n");
	printf("%p\n", &var2);

	printf("%p\n", &var2.i);
	printf("%d\n", var2.i);
	printf("%p\n", &var2.c);
	printf("%c\n", var2.c);
	printf("%p\n", &var2.f);
	printf("%f\n", var2.f);

	printf("--- var3 ---\n");
	printf("%p\n", &var3);

	printf("%p\n", &var3.i);
	printf("%d\n", var3.i);
	printf("%p\n", &var3.c);
	printf("%c\n", var3.c);
	printf("%p\n", &var3.f);
	printf("%f\n", var3.f);

	//-------------------------------------------------------
	//2. Pass as argument to function & return from function
	//-------------------------------------------------------
	struct static_fields var4 = my_function(var2);

	printf("\n--- BLOCK 2 ---\n");
	printf("--- var4 ---\n");
	printf("%p\n", &var4);

	printf("%p\n", &var4.i);
	printf("%d\n", var4.i);
	printf("%p\n", &var4.c);
	printf("%c\n", var4.c);
	printf("%p\n", &var4.f);
	printf("%f\n", var4.f);

	printf("--- var2 ---\n");
	printf("%p\n", &var2);

	printf("%p\n", &var2.i);
	printf("%d\n", var2.i);
	printf("%p\n", &var2.c);
	printf("%c\n", var2.c);
	printf("%p\n", &var2.f);
	printf("%f\n", var2.f);

	//-------------------------------------------------------
	//3. Pointer to a struct
	//-------------------------------------------------------
	struct static_fields* p = &var4;

	(*p).i = 10;
	(*p).c = 'z';
	(*p).f = 4.7;

	printf("\n--- BLOCK 3 ---\n");
	printf("--- var4 ---\n");
	printf("%p\n", &var4);

	printf("%p\n", &var4.i);
	printf("%d\n", var4.i);
	printf("%p\n", &var4.c);
	printf("%c\n", var4.c);
	printf("%p\n", &var4.f);
	printf("%f\n", var4.f);

	return 0;

}





