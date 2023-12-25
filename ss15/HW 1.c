#include <stdio.h>

int isFibonacci(int n) {
    int a = 0, b = 1, temp;
    while (b < n) {
        temp = b;
        b = a + b;
        a = temp;
    }
    return (b == n);
}
int main() {
    int dong, cot;
    printf("Nhap so dong: ");
    scanf("%d", &dong);
    printf("Nhap so cot: ");
    scanf("%d", &cot);
    int a[dong][cot];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < dong; ++i) {
        for (int j = 0; j < cot; ++j) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("Cac so Fibonacci trong mang:\n");
    for (int i = 0; i < dong; ++i) {
        for (int j = 0; j < cot; ++j) {
            if (isFibonacci(a[i][j])) {
                printf("%d ", a[i][j]);
            }
        }
    }

    return 0;
}
