#include <stdio.h>

int main() {
    int choice, n, i, sum, max_odd_divisor;
    printf("Nhap so nguyen n: ");
    scanf_s("%d", &n);

    printf("PRACTICE\n");
    printf("1. In day so chia het cho 2 va giam dan (n >= số >= 2)\n");
    printf("2. In cac so nho hon n va tinh tong\n");
    printf("3. In ra cac uoc so chan cua n\n");
    printf("4. In ra cac uoc so le va so luong cac uoc le cua n\n");
    printf("5. In ra uoc so le lon nhat cua n\n");
    printf("6. Thoat\n");

    printf("Lua chon cua ban: ");
    scanf_s("%d", &choice);

    switch (choice) {
        case 1:
            printf("Day so chia het cho 2 va giam dan tu %d den 2 la: ", n);
            for (i = n; i >= 2; i--) {
                if (i % 2 == 0) {
                    printf("%d ", i);
                }
            }
            break;
        case 2:
            sum = 0;
            printf("Cac so nho hon %d la: ", n);
            for (i = 1; i < n; i++) {
                printf("%d ", i);
                sum += i;
            }
            printf("\nTong cac so nho hon %d la %d", n, sum);
            break;
        case 3:
            printf("Cac uoc so chan cua %d la: ", n);
            for (i = 1; i <= n; i++) {
                if (n % i == 0 && i % 2 == 0) {
                    printf("%d ", i);
                }
            }
            break;
        case 4:
            sum = 0;
            printf("Cac uoc so le cua %d la: ", n);
            for (i = 1; i <= n; i++) {
                if (n % i == 0 && i % 2 == 1) {
                    printf("%d ", i);
                    sum++;
                }
            }
            printf("\nSo luong cac uoc so le cua %d la %d", n, sum);
            break;
        case 5:
            max_odd_divisor = 1;
            printf("Cac uoc so le cua %d la: ", n);
            for (i = 1; i <= n; i++) {
                if (n % i == 0 && i % 2 == 1) {
                    printf("%d ", i);
                    if (i > max_odd_divisor) {
                        max_odd_divisor = i;
                    }
                }
            }
            printf("\nUoc so le lon nhat cua %d la %d", n, max_odd_divisor);
            break;
        case 6:
            printf("Thoat");
            break;
        default:
            printf("Lua chon khong hop le");
    }

    return 0;
}