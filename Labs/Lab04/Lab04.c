#include <stdio.h>
#include <stdlib.h>
int global_num = 5;
int main()
{
int main_local_num = 33;
    void *stack_ptr;
    asm volatile ("mov %%esp,%0;" : "=g" (stack_ptr));
    printf("\n\nMain: Value of ESP register is %p\n", stack_ptr);
    print("\n\nMemory location": %p\n, (void *) &global_num);
    print("\n\nMemory location": %p\n, (void *) &main_local_num);

    return 0;
}
