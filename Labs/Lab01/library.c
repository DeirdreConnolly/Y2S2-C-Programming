// Lab01.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>


int main()
{
    int number = 31;
    char letter = 'a';

    printf("Number is \t %d : %x\n", number, number);
    printf("Number is \t %c : %d : %x\n", letter, letter, letter);
    printf("Press enter to continue");
    getchar();

    return 0;
}

