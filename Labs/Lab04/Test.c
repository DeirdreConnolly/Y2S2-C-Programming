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

    printf("\nGlobal num: %d", global_num);

    int called = 0;
{
    if (called < 3) {
        test();
    }
    else {
        printf("That's enough."
    }

    return 0;
}

void test()

    int test_local_num  = 5;
    static int test_static_num = 0;

    void *stack_ptr = NULL;
    asm volatile ("mov %%esp,%0;" : "=g" (stack_ptr));
    printf("\nTest: Value of ESP register is %d\n", stack_ptr);
    printf("\nLocation in memory: %p\n", (void *) &global_num);

    global_num = global_num++;
    test_local_num = test_local_num++;
    test_static_num = test_static_num++;

    printf("\nTest: Address of test_local_num is: %p, value is %d", &test_local_num);
    printf("\nTest: Address of test_static_num is: %p, value is %d", &test_static_num);
    called++;











}
