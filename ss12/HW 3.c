#include <stdio.h>

int la_so_nguyen_to(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void kiem_tra_mang(int arr[], int n, int *dem) {
    for (int i = 0; i < n; i++) {
        if (la_so_nguyen_to(arr[i])) {
            printf("%d la so nguyen to\n", arr[i]);
            (*dem)++;
        } else {
            printf("%d khong phai la so nguyen to\n", arr[i]);
        }
    }
}

int main() {
    int n1, n2;
    printf("Nhap so luong phan tu cua mang 1: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Nhap cac phan tu cua mang 1: ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Nhap so luong phan tu cua mang 2: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Nhap cac phan tu cua mang 2: ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    int dem1 = 0, dem2 = 0;
    printf("Kiem tra mang 1:\n");
    kiem_tra_mang(arr1, n1, &dem1);
    printf("Kiem tra mang 2:\n");
    kiem_tra_mang(arr2, n2, &dem2);

    if (dem1 > dem2) {
        printf("Mang 1 co nhieu so nguyen to hon\n");
    } else if (dem1 < dem2) {
        printf("Mang 2 co nhieu so nguyen to hon\n");
    } else {
        printf("Ca hai mang đeu co so luong so nguyen to bang nhau\n");
    }

    return 0;
}