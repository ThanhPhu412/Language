#include <stdio.h>

void tinh_toan(int a, int b, int c) {
    int so[3] = {a, b, c};
    int cap = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            printf("Cap so thu %d :\n", cap++ );
            printf("%d * %d = %d\n", so[i], so[j], so[i] * so[j]);
            if (so[i] % so[j] == 0) {
                printf("%d / %d = %d\n", so[i], so[j], so[i] / so[j]);
            } else if (so[j] % so[i] == 0) {
                printf("%d / %d = %d\n", so[j], so[i], so[j] / so[i]);
            } else {
                printf("%d khong chia het cho %d\n", so[i], so[j]);
                printf("%d khong chia het cho %d\n", so[j], so[i]);
            }
        }
    }
}

int main() {
    int a, b, c;
    printf("Nhap vao 3 so a, b, c: ");
    scanf("%d%d%d", &a, &b, &c);
    tinh_toan(a, b, c);
    return 0;
}