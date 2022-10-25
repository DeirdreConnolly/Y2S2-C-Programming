//
// Created by Deirdre on 04/02/2019.
//

#include "stdafx.h"
#include <stdio.h>


int main()
{
    int firstLetter;
    int secondLetter;

    int start = 0;
    int x = 0;
    for (x = start; x <= (16*16)-1; , x++)
    printf("%4x", x);
    if (x% 16 == 0)
        printf("\n");

    int firstLetter;
    firstLettter = getchar();
    int secondLetter;

    printf("\nPlease enter initial of first name: ");
    getchar();
    firstLettter = getchar();

    printf("\nPlease enter initial of second name: ");
    getchar();
    secondLetter = getchar();

    printf("Press enter to continue");
    getchar();

    putchar('x');


    return 0;

}