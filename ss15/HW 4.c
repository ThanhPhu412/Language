#include <stdio.h>
#include <stdbool.h>

bool laSNT(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int soDong, soCot;
    printf("Nhap so dong: ");
    scanf("%d", &soDong);
    printf("Nhap so cot: ");
    scanf("%d", &soCot);
    int a[soDong][soCot];
    for (int i = 0; i < soDong; i++) {
        for (int j = 0; j < soCot; j++) {
            printf("Nhap phan tu a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    int maxSNT = 0, hangMaxSNT = -1;
    for (int i = 0; i < soDong; i++) {
        int snt = 0;
        for (int j = 0; j < soCot; j++) {
            if (laSNT(a[i][j]))
                snt++;
        }
        if (snt >= maxSNT) {
            maxSNT = snt;
            hangMaxSNT = i;
        }
    }
    printf("Hang %d co nhieu so nguyen to nhat\n", hangMaxSNT);
    printf("So luong so nguyen to o hang %d : %d\n", hangMaxSNT, maxSNT);
    return 0;
}
