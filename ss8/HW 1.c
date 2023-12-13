#include <stdio.h>

int main() {
    int n, i;
    printf("Nhập số phần tử của mảng: ");
    scanf("%d", &n);
    int arry[n];

    printf("Nhập giá trị các phần tử của mảng: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arry[i]);
    }

    int max = arry[0];
    int min = arry[0];

    for(i = 1; i < n; i++) {
        if(arry[i] > max) {
            max = arry[i];
        }
        if(arry[i] < min) {
            min = arry[i];
        }
    }

    printf("Giá trị lớn nhất trong mảng là: %d\n", max);
    printf("Giá trị nhỏ nhất trong mảng là: %d\n", min);

    return 0;
}
