#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int global_num = 5;

int main() {
    int main_local_num = 33;

    void *stack_ptr;
    asm volatile ("mov %%esp, %0;" : "=g" (stack_ptr));
    printf("\n\nMain: Value of ESP regulator: %p\n", stack_ptr);
    printf("\n\nLocation in memory: %p", &main_local_num);
    getchar();


    return 0;






}