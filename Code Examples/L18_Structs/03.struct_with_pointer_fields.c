

#include <stdio.h>
#include <stdlib.h>

//--------------------------------------//
//	Very basic struct					//	
//--------------------------------------//

struct pointer_fields {
	int i;
	char c;
	int* my_array;
};

//--------------------------------------//
//	my_function							//	
//--------------------------------------//

struct pointer_fields my_function(struct pointer_fields s) {

	struct pointer_fields aux;
	aux.i = s.i + 3;
	if (s.c == 'b')
		aux.c = 'c';
	else
		aux.c = s.c;

	int* array_value = (int*)malloc(10 * sizeof(int));
	for (int i = 0; i < 10; i++)
		array_value[i] = i;
	aux.my_array = array_value;

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
	struct pointer_fields var1 = { 3, 'a', NULL };

	//1.2. Initialise a varaible field by field
	struct pointer_fields var2;
	var2.i = 4;
	var2.c = 'b';
	int* a = (int*)malloc(5 * sizeof(int));
	for (int i = 0; i < 5; i++)
		a[i] = i + 10;
	var2.my_array = a;

	//1.3. Initialise a variable by making it equal to other variable
	struct pointer_fields var3 = var2;
	var3.my_array[0] = 37;

	//1.4. Print the info to see they are different.
	printf("\n--- BLOCK 1 ---\n");
	printf("--- var1 ---\n");
	printf("%p\n", &var1);

	printf("%p\n", &var1.i);
	printf("%d\n", var1.i);
	printf("%p\n", &var1.c);
	printf("%c\n", var1.c);
	printf("%p\n", &var1.my_array);
	printf("%p\n", var1.my_array);
	//printf("%d\n", (var1.my_array[0])); //--> We do not do this, as our pointer is pointing to NULL

	printf("--- var2 ---\n");
	printf("%p\n", &var2);

	printf("%p\n", &var2.i);
	printf("%d\n", var2.i);
	printf("%p\n", &var2.c);
	printf("%c\n", var2.c);
	printf("%p\n", &var2.my_array);
	printf("%p\n", var2.my_array);
	printf("%d\n", (var2.my_array[0]));

	printf("--- var3 ---\n");
	printf("%p\n", &var3);

	printf("%p\n", &var3.i);
	printf("%d\n", var3.i);
	printf("%p\n", &var3.c);
	printf("%c\n", var3.c);
	printf("%p\n", &var3.my_array);
	//PAY ATTENTION: var3.my_array and var2.my_array ARE SHARED!!!
	printf("%p\n", var3.my_array); //
	printf("%d\n", (var3.my_array[0]));

	//-------------------------------------------------------
	//2. Pass as argument to function & return from function
	//-------------------------------------------------------

	struct pointer_fields var4 = my_function(var2);

	printf("\n--- BLOCK 2 ---\n");
	printf("--- var4 ---\n");
	printf("%p\n", &var4);

	printf("%p\n", &var4.i);
	printf("%d\n", var4.i);
	printf("%p\n", &var4.c);
	printf("%c\n", var4.c);
	printf("%p\n", &var4.my_array);
	printf("%p\n", var4.my_array);
	printf("%d\n", (var4.my_array[0]));

	printf("--- var2 ---\n");
	printf("%p\n", &var2);

	printf("%p\n", &var2.i);
	printf("%d\n", var2.i);
	printf("%p\n", &var2.c);
	printf("%c\n", var2.c);
	printf("%p\n", &var2.my_array);
	printf("%p\n", var2.my_array);
	printf("%d\n", (var2.my_array[0]));

	//-------------------------------------------------------
	//3. Pointer to a struct
	//-------------------------------------------------------
	struct pointer_fields* p = &var4;

	(*p).i = 10;
	(*p).c = 'z';
	(*p).my_array[0] = 10000;

	printf("\n--- BLOCK 3 ---\n");
	printf("--- var4 ---\n");
	printf("%p\n", &var4);

	printf("%p\n", &var4.i);
	printf("%d\n", var4.i);
	printf("%p\n", &var4.c);
	printf("%c\n", var4.c);
	printf("%p\n", &var4.my_array);
	printf("%p\n", var4.my_array);
	printf("%d\n", (var4.my_array[0]));

	return 0;

}





