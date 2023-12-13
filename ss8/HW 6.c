#include <stdio.h>

int main() {
    int n, deleteIndex;
    printf("Nhập số phần tử của mảng: ");
    scanf("%d", &n);
    int oldNumbers[n];

    printf("Nhập giá trị các phần tử của mảng: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &oldNumbers[i]);
    }

    printf("Nhập chỉ số phần tử cần xóa: ");
    scanf("%d", &deleteIndex);

    int newNumbers[n-1];
    for(int i = 0; i < deleteIndex; i++) {
        newNumbers[i] = oldNumbers[i];
    }
    for(int i = deleteIndex+1; i < n; i++) {
        newNumbers[i-1] = oldNumbers[i];
    }

    printf("Mảng sau khi xóa phần tử: ");
    for(int i = 0; i < n-1; i++) {
        printf("%d ", newNumbers[i]);
    }

    return 0;
}
