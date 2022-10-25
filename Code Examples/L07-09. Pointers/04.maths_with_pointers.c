
#include <stdio.h>

int main() {

    int a[3] = {1,2,3};
    int* p_a = &a[0];

    printf("p_a address it is pointing at = %p\n", p_a);
    printf("p_a next address = %p\n", p_a + 1);
    printf("p_a previous address = %p\n", p_a - 1);
    printf("p_a 100 addresses after the one it is pointing at = %p\n", p_a + 100);

    char b[3] = {'a', 'b', 'c'};
    char* p_b = &b[0];

    printf("p_c address it is pointing at = %p\n", p_b);
    printf("p_c next address = %p\n", p_b + 1);
    printf("p_c previous address = %p\n", p_b - 1);
    printf("p_c 100 addresses after the one it is pointing at = %p\n", p_b + 100);

    return 0;
}







