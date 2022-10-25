#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main() {
    char a[100] = "What is your name?";
    char* b = NULL;
    b = strstr(a, "is");
    printf("%s\n",b);
    return 0;}