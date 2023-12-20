#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int var1 = 10;
    int var2 = 20;

    printf("Truoc khi doi cho:\n");
    printf("var1 = %d, var2 = %d\n", var1, var2);
    printf("Hieu cua var1 va var2: %d\n", var1 - var2);

    swap(&var1, &var2);

    printf("\nSau khi doi cho:\n");
    printf("var1 = %d, var2 = %d\n", var1, var2);
    printf("Hieu cua var1 va var2: %d\n", var1 - var2);

    return 0;
}
