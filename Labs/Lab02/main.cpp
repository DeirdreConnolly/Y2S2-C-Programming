#include <iostream>
#include <stdio.h>
#include <limits.h>

int main() {
    int num = 0XFFFF;
    char letter1 = 'A';
    char letter2 = 'B';

    void *stack_ptr;
    _asm volatile("mov %%ebp, %0;" : "=g" (stack_ptr));
    printf("Value of EBP register: %p\n", stack_ptr);
    printf("\n\nStart location of num: 0x%p", &num);

    printf("Press return to continue");

    printf("\nLetter 1: %d %x %c", letter1, letter1, letter1);
    printf("\nLetter 2: %d %x %c", letter2, letter2, letter2);
    printf("\nLetter 1 allocated: %d byte(s)", sizeof(letter1));
    printf("\nLetter 1 max value: %d", CHAR_MAX);
    printf("\nLetter 1 min value: %d", CHAR_MIN);
    printf("\nNum value: %d %x", num, num);
    printf("\nNum uses: %d byte(s)", sizeof(num));
    printf("Max/Min value in num: %d %d", INT_MAX, INT_MIN);

    getchar();


    return 0;



}