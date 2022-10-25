
#include <stdio.h>
#include <stdlib.h>

enum Boolean { False, True };
typedef enum Boolean bool;

//--------------------------------------//
//	is_magic_sequence_first				//	
//--------------------------------------//
bool is_magic_sequence_first(int* a, int size) {
	//1. A variable to denote whether it is a magic sequence so far
	bool is_magic = True;

	//2. A while loop in which we tried the next element of the list
	int index = 0;
	while ((is_magic == True) && (index < size)) {
		//2.1. We take the index of a at that position
		int value = a[index];

		//2.2. We make a loop to count how many of this index are there 
		int count = 0;
		for (int i = 0; i < size; i++) {
			//2.2.1. We check the condition
			if (a[i] == index)
				count = count + 1;
		}

		//2.3. We take the index of a at that position
		if (count != value)
			is_magic = False;

		//2.4. We increase the index to be checked
		index = index + 1;
	}

	//3. Return is_magic
	return is_magic;
}

//--------------------------------------//
//	is_magic_sequence_second			//	
//--------------------------------------//
bool is_magic_sequence_second(int* a, int size) {
	//1. A variable to denote whether it is a magic sequence so far
	bool is_magic = True;

	//2. A while loop in which we tried the next element of the list
	int index = 0;
	while ((is_magic == True) && (index < size)) {
		//2.1. We take the index of a at that position
		int value = a[index];

		//2.2. We make a loop to count how many of this index are there 
		//A bit better approach: 
		//An extra variable for checking that we do not count more elements than needed
		int count = 0;
		int i = 0;

		while ((count <= value) && (i < size)) {
			//2.2.1. We check the condition
			if (a[i] == index)
				count = count + 1;
			//2.2.2. We increase the index
			i = i + 1;
		}

		//2.3. We take the index of a at that position
		if (count != value)
			is_magic = False;

		//2.4. We increase the index to be checked
		index = index + 1;
	}

	//3. Return is_magic
	return is_magic;
}

//--------------------------------------//
//	is_magic_sequence_third				//	
//--------------------------------------//
bool is_magic_sequence_third(int* a, int size) {
	//1. A variable to denote whether it is a magic sequence so far
	bool is_magic = True;

	//2. A while loop in which we tried the next element of the list
	int index = 0;
	while ((is_magic == True) && (index < size)) {
		//2.1. We take the index of a at that position
		int value = a[index];

		//2.2. We make a loop to count how many of this index are there 
		//An even better approach: 
		//An extra variable for checking that we are still in time of achieving the ones left
		int left = value;
		int i = 0;
		while ((left >= 0) && ((size - i) >= left)) {
			//2.2.1. We check the condition
			if (a[i] == index)
				left = left - 1;
			//2.2.2. We increase the index
			i = i + 1;
		}

		//2.3. We take the index of a at that position

		//Options 1 and 2
		if (left != 0)
			is_magic = False;

		//2.4. We increase the index to be checked
		index = index + 1;
	}

	//3. Return is_magic
	return is_magic;
}


//--------------------------------------//
//	is_magic_sequence_first_annotated	//	
//--------------------------------------//
bool is_magic_sequence_first_annotated(int* a, int size) {
	//1. A variable to denote whether it is a magic sequence so far
	bool is_magic = True;

	//2. A while loop in which we tried the next element of the list
	int index = 0;
	int total_loop_iterations = 0;
	while ((is_magic == True) && (index < size)) {
		//2.1. We take the index of a at that position
		int value = a[index];

		//2.2. We make a loop to count how many of this index are there 
		int count = 0;
		for (int i = 0; i < size; i++) {
			total_loop_iterations++;
			//2.2.1. We check the condition
			if (a[i] == index)
				count = count + 1;
		}

		//2.3. We take the index of a at that position
		if (count != value)
			is_magic = False;

		//2.4. We increase the index to be checked
		index = index + 1;
	}

	printf("total_loop_iterations = %d\n", total_loop_iterations);
	//3. Return is_magic
	return is_magic;
}

//--------------------------------------//
//	is_magic_sequence_second_annotated	//	
//--------------------------------------//
bool is_magic_sequence_second_annotated(int* a, int size) {
	//1. A variable to denote whether it is a magic sequence so far
	bool is_magic = True;

	//2. A while loop in which we tried the next element of the list
	int index = 0;
	int total_loop_iterations = 0;
	while ((is_magic == True) && (index < size)) {
		//2.1. We take the index of a at that position
		int value = a[index];

		//2.2. We make a loop to count how many of this index are there 
		//A bit better approach: 
		//An extra variable for checking that we do not count more elements than needed
		int count = 0;
		int i = 0;

		while ((count <= value) && (i < size)) {
			total_loop_iterations++;
			//2.2.1. We check the condition
			if (a[i] == index)
				count = count + 1;
			//2.2.2. We increase the index
			i = i + 1;
		}

		//2.3. We take the index of a at that position
		if (count != value)
			is_magic = False;

		//2.4. We increase the index to be checked
		index = index + 1;
	}

	printf("total_loop_iterations = %d\n", total_loop_iterations);
	//3. Return is_magic
	return is_magic;
}

//--------------------------------------//
//	is_magic_sequence_third_annotated	//	
//--------------------------------------//
bool is_magic_sequence_third_annotated(int* a, int size) {
	//1. A variable to denote whether it is a magic sequence so far
	bool is_magic = True;

	//2. A while loop in which we tried the next element of the list
	int index = 0;
	int total_loop_iterations = 0;
	while ((is_magic == True) && (index < size)) {
		//2.1. We take the index of a at that position
		int value = a[index];

		//2.2. We make a loop to count how many of this index are there 
		//An even better approach: 
		//An extra variable for checking that we are still in time of achieving the ones left
		int left = value;
		int i = 0;
		while ((left >= 0) && ((size - i) >= left)) {
			total_loop_iterations++;
			//2.2.1. We check the condition
			if (a[i] == index)
				left = left - 1;
			//2.2.2. We increase the index
			i = i + 1;
		}

		//2.3. We take the index of a at that position

		//Options 1 and 2
		if (left != 0)
			is_magic = False;

		//2.4. We increase the index to be checked
		index = index + 1;
	}

	printf("total_loop_iterations = %d\n", total_loop_iterations);
	//3. Return is_magic
	return is_magic;
}

//--------------------------------------//
//	main								//	
//--------------------------------------//
int main() {

	int a[4] = { 1, 0, 2, 1 };
	bool res1 = is_magic_sequence_first(a, 4);
	printf("res1 = %d\n", res1);
	res1 = is_magic_sequence_second(a, 4);
	printf("res1 = %d\n", res1);
	res1 = is_magic_sequence_third(a, 4);
	printf("res1 = %d\n", res1);

	int b[4] = { 2, 0, 2, 0 };
	bool res2 = is_magic_sequence_first(b, 4);
	printf("res2 = %d\n", res2);
	res2 = is_magic_sequence_second(b, 4);
	printf("res2 = %d\n", res2);
	res2 = is_magic_sequence_third(b, 4);
	printf("res2 = %d\n", res2);


	//Magic series of size n >= 7 follow a common pattern
	//Indexes:  0   1   2   3   4  ... n-4  n-3  n-2  n-1
	//Values:  n-4  2   1   0   0       1    0    0    0

	//For example: 
	//0  1  2  3  4  5  6  7  8  9
	//6  2  1  0  0  0  1  0  0  0

	//Thus, if we generate a fake magic series turning his indexes 3, 4 and 5 to take the value let's say 10, we will 
	//screw up its possibilities of being a magic serie.
	//However, our poor options 1 and 2 will not realise of such a thing. But, our option 3 will do. 
	//Let's proceed with it: 
	int c[10];
	for (int i = 0; i < 10; i++)
		c[i] = 0;
	c[0] = 6;
	c[1] = 2;
	c[2] = 1;
	c[6] = 1;

	bool res3 = is_magic_sequence_first(c, 10);
	printf("res3 = %d\n", res3);
	res3 = is_magic_sequence_second(c, 10);
	printf("res3 = %d\n", res3);
	res3 = is_magic_sequence_third(c, 10);
	printf("res3 = %d\n", res3);

	//Final example
	int d[100000];
	for (int i = 0; i < 100000; i++)
		d[i] = 0;
	d[0] = 100000 - 4;
	d[1] = 2;
	d[2] = 1;
	d[3] = 1;
	d[4] = 1;
	d[100000 - 4] = 1;

	bool res4 = is_magic_sequence_first_annotated(d, 100000);
	printf("res4 = %d\n", res4);
	res4 = is_magic_sequence_second_annotated(d, 100000);
	printf("res4 = %d\n", res4);
	res4 = is_magic_sequence_third_annotated(d, 100000);
	printf("res4 = %d\n", res4);

	return 0;
}

