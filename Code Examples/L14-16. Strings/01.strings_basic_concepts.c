
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//--------------------------------------//
//	functions							//	
//--------------------------------------//

void my_function1(char arg[]) {
	arg[2] = 'z';
}

char* my_function2() {
	char res[] = "Test";
	return res;
}

char* my_function3() {
	char* res = (char*)malloc(5 * sizeof(char));
	res[0] = 'T';
	res[1] = 'e';
	res[2] = 's';
	res[3] = 't';
	res[4] = '\0';
	return res;
}

//--------------------------------------//
//	main								//	
//--------------------------------------//

int main() {

	//---------------------//
	//   1. Fixed Size     //
	//---------------------//
	printf("\n--- 1. Fixed Size ---\n");

	char str_one[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	printf("str_one = %s. Length = %d\n", str_one, strlen(str_one));

	str_one[2] = '\0';
	printf("str_one = %s. Length = %d\n", str_one, strlen(str_one));

	str_one[2] = 'l';
	printf("str_one = %s. Length = %d\n", str_one, strlen(str_one));

	//-------------------------------------------------------//
	//   2. Set all the elements of the string at a time     //
	//-------------------------------------------------------//
	printf("\n--- 2. Set all the elements of the string at a time ---\n");

	//2.1. You can "declare + assign" a new string
	char str_two[] = "Hola";
	str_two[2] = 'L';
	printf("str_two = %s\n", str_two);

	//2.2. You can "declare + assign" a new ---const--- string
	char* str_three = "Bonjour";
	//str_three[2] = 'N'; //--> Execution error. Try to modify a const variable.
	printf("str_three = %s\n", str_three);

	//--------------------------------------------//
	//   3. Strings do not support assignment     //
	//--------------------------------------------//
	//3.1. You ---can--- "declare + assign" a new string / const string to a literal (cf. 2.1 and 2.2, resp.)

	//3.2. You ---cannot--- "declare + assign" a new string to another string.
	//char str_four[] = str_two; //--> Compilation error

	//3.3. You ---cannot--- assign one existing string to another string.
	//str_one = "Hola"; //--> Compilation error

	//-------------------------------------------------------//
	//   4. You can access to elements out of the range of   //
	//      the string with no compilation nor runtime error //
	//-------------------------------------------------------//
	printf("\n--- 4. You can access to elements out of the range of the string ---\n");

	//4.1. Change one character of the string to whatever it is in an address
	str_one[2] = str_one[216];
	printf("str_one = %s\n", str_one);
	str_one[2] = 'l';

	//4.2. Use the string to change a position of memory that does not belong to the string!
	printf("Address we look at = %p\n", &str_one[79]);
	printf("Value before = %c\n", str_one[79]);
	str_one[79] = str_one[216];
	printf("Value after = %c\n", str_one[79]);

		
	//--------------------------------------------------//
	//   5. Strings passed as arguments to functions    //
	//--------------------------------------------------//
	printf("\n--- 5. Strings passed as arguments to functions ---\n");

	my_function1(str_one);
	printf("str_one = %s\n", str_one);

	//---------------------------------------------------//
	//   6. Strings returned as result from functions    //
	//---------------------------------------------------//
	printf("\n--- 6. Strings passed as arguments to functions ---\n");

	//6.1. The memory of the stack dissapears when my_function2 exits. Thus, the pointer str_five points to senseless content.
	char* str_five = my_function2();
	printf("str_five = %s\n", str_five);

	//6.2. By reserving the string with malloc within my_function3, its content remains once my_function3 exits.
	char* str_six = my_function3();
	printf("str_six = %s\n", str_six);

	//6.3. Finally, str_six points to the string, but it was not declared using the pointer notation (cf. 2.2).
	//Thus, the content of the string pointed by str_six can be modified (not as the content of the string declared + assign in 2.2).
	str_six[2] = 'z';
	printf("str_six = %s\n", str_six);

	return 0;

}

