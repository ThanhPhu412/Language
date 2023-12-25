#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int dong, cot;
    printf("Nhap so dong: ");
    scanf("%d", &dong);
    printf("Nhap so cot: ");
    scanf("%d", &cot);

    int a[dong][cot];
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            printf("Nhap phan tu a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for (int j = 0; j < cot; j++) {
        swap(&a[0][j], &a[1][j]);
    }

    printf("Mang sau khi hoan vi hai hang dau tien:\n");
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}