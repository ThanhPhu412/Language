#include <stdio.h>

int main() {
    int var = 10;
    int *ptr;

    ptr = &var;

    printf("Gia tri cua var: %d\n", var);
    printf("Dia chi cua var: %p\n", &var);

    printf("Gia tri cua var thong qua ptr: %d\n", *ptr);
    printf("Dia chi cua var thong qua ptr: %p\n", ptr);

    return 0;
}
