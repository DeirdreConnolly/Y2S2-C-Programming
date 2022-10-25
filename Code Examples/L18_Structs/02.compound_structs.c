
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
//	Compound struct						//	
//--------------------------------------//

struct compound {
	int a;
	struct static_fields s;
};

//--------------------------------------//
//	my_function							//	
//--------------------------------------//

struct compound my_function(struct compound arg) {

	struct compound var;
	var.a = arg.a + 1000;

	struct static_fields aux = arg.s;
	var.s = aux;

	return var;
}

//--------------------------------------//
//	main								//	
//--------------------------------------//
int main(int argc, char* argv[]) {

	//----------------------------------------------------
	//1. See the struct definition and initialisation
	//----------------------------------------------------

	//1.1. Initialise a varaible straight away
	//struct static_fields sf = { 3, 'a', 5.0 };
	//struct compound var1 = { 10, sf };         //--> This fails

	struct compound var1 = { 10, 3, 'a', 5.0 };

	//1.2. Initialise a varaible field by field
	struct compound var2;
	var2.a = 50;
	var2.s.i = 4;
	var2.s.c = 'b';
	var2.s.f = (float) 10.2;

	//1.3. Initialise a variable by making it equal to other variable
	struct compound var3 = var2;

	//1.4. Print the info to see they are different.
	printf("\n--- BLOCK 1 ---\n");
	printf("--- var1 ---\n");
	printf("%p\n", &var1);

	printf("%p\n", &var1.a);
	printf("%d\n", var1.a);

	printf("%p\n", &var1.s.i);
	printf("%d\n", var1.s.i);
	printf("%p\n", &var1.s.c);
	printf("%c\n", var1.s.c);
	printf("%p\n", &var1.s.f);
	printf("%f\n", var1.s.f);

	printf("--- var2 ---\n");
	printf("%p\n", &var2);

	printf("%p\n", &var2.a);
	printf("%d\n", var2.a);

	printf("%p\n", &var2.s.i);
	printf("%d\n", var2.s.i);
	printf("%p\n", &var2.s.c);
	printf("%c\n", var2.s.c);
	printf("%p\n", &var2.s.f);
	printf("%f\n", var2.s.f);

	printf("--- var3 ---\n");
	printf("%p\n", &var3);

	printf("%p\n", &var3.a);
	printf("%d\n", var3.a);

	printf("%p\n", &var3.s.i);
	printf("%d\n", var3.s.i);
	printf("%p\n", &var3.s.c);
	printf("%c\n", var3.s.c);
	printf("%p\n", &var3.s.f);
	printf("%f\n", var3.s.f);

	//-------------------------------------------------------
	//2. Pass as argument to function & return from function
	//-------------------------------------------------------
	struct compound var4 = my_function(var3);

	printf("\n--- BLOCK 2 ---\n");
	printf("--- var4 ---\n");
	printf("%p\n", &var4);

	printf("%p\n", &var4.a);
	printf("%d\n", var4.a);

	printf("%p\n", &var4.s.i);
	printf("%d\n", var4.s.i);
	printf("%p\n", &var4.s.c);
	printf("%c\n", var4.s.c);
	printf("%p\n", &var4.s.f);
	printf("%f\n", var4.s.f);

	printf("--- var2 ---\n");
	printf("%p\n", &var2);

	printf("%p\n", &var2.a);
	printf("%d\n", var2.a);

	printf("%p\n", &var2.s.i);
	printf("%d\n", var2.s.i);
	printf("%p\n", &var2.s.c);
	printf("%c\n", var2.s.c);
	printf("%p\n", &var2.s.f);
	printf("%f\n", var2.s.f);

	//-------------------------------------------------------
	//3. Pointer to a struct
	//-------------------------------------------------------
	struct compound* p = &var4;

	(*p).a = 400;
	((*p).s).i = 10;
	((*p).s).c = 'z';
	((*p).s).f = 4.7;

	printf("\n--- BLOCK 3 ---\n");
	printf("--- var4 ---\n");
	printf("%p\n", &var4);

	printf("%p\n", &var4.a);
	printf("%d\n", var4.a);

	printf("%p\n", &var4.s.i);
	printf("%d\n", var4.s.i);
	printf("%p\n", &var4.s.c);
	printf("%c\n", var4.s.c);
	printf("%p\n", &var4.s.f);
	printf("%f\n", var4.s.f);

	return 0;

}





