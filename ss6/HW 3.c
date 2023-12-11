#include <stdio.h>

int main() {
    int choice, num1, num2, num3, sum, max, min;
    float average;

    printf("Nhap so thu nhat: ");
    scanf_s("%d", &num1);

    printf("Nhap so thu hai: ");
    scanf_s("%d", &num2);

    printf("Nhap so thu ba: ");
    scanf_s("%d", &num3);

    printf("CACULATOR\n");
    printf("1. Tong 3 so nguyen\n");
    printf("2. Trung binh cong cua 3 so nguyen\n");
    printf("3. So lon nhat, nho nhat trong 3 so\n");
    printf("4. Thoat\n");

    printf("Lua chon cua ban: ");
    scanf_s("%d", &choice);

    switch (choice) {
        case 1:
            sum = num1 + num2 + num3;
            printf("Tong cua %d, %d va %d la %d", num1, num2, num3, sum);
            break;
        case 2:
            average = (float)(num1 + num2 + num3) / 3;
            printf("Trung binh cong cua %d, %d va %d la %.2f", num1, num2, num3, average);
            break;
        case 3:
            max = num1;
            if (num2 > max) {
                max = num2;
            }
            if (num3 > max) {
                max = num3;
            }
            min = num1;
            if (num2 < min) {
                min = num2;
            }
            if (num3 < min) {
                min = num3;
            }
            printf("So lon nhat trong %d, %d va %d la %d\n", num1, num2, num3, max);
            printf("So nho nhat trong %d, %d va %d la %d", num1, num2, num3, min);
            break;
        case 4:
            printf("Thoat");
            break;
        default:
            printf("Lua chon khong hop le");
    }

    return 0;
}