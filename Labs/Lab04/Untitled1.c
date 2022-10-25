#include <stdio.h>
#include <stdlib.h>

int global_num = 5;

int main()
{
int main_local_num = 33;
    void *stack_ptr;
    asm volatile ("mov %%esp,%0;" : "=g" (stack_ptr));
    printf("\nMain: Value of ESP register is %p\n", stack_ptr);
    printf("\nLocation in memory: %p\n", (void *) &global_num);
    printf("\nLocation in memory: %p\n", (void *) &main_local_num);

    return 0;
}

void test()
{
    void *stack_ptr = NULL;
    asm volatile ("mov %%esp,%0;" : "=g" (stack_ptr));
    printf("\n\nTest: Value of ESP register is %d\n", stack_ptr);
    printf("\n\nLocation in memory: %d\n", (void *) &global_num);

    global_num = global_num++;
}
