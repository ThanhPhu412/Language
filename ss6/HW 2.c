#include <stdio.h>

int main() {
    int choice, num1, num2, sum, hieu, tich, thuong, du, UCln, BCnn;

    printf("Nhap so thu nhat: ");
    scanf_s("%d", &num1);

    printf("Nhap so thu hai: ");
    scanf_s("%d", &num2);

    printf("CACULATOR\n");
    printf("1. Tong 2 so\n");
    printf("2. Hieu 2 so\n");
    printf("3. TIch 2 so\n");
    printf("4. Thuong 2 so\n");
    printf("5. So du trong phep chia 2 so\n");
    printf("6. Uoc chung lon nhat\n");
    printf("7. Boi chung nho nhat\n");
    printf("8. Thoat\n");

    printf("Lua chon cia ban: ");
    scanf_s("%d", &choice);

    switch (choice) {
        case 1:
            sum = num1 + num2;
            printf("Tong cua %d va %d la %d", num1, num2, sum);
            break;
        case 2:
            hieu = num1 - num2;
            printf("Hieu cua %d va %d la %d", num1, num2, hieu);
            break;
        case 3:
            tich = num1 * num2;
            printf("Tich cua %d và %d la %d", num1, num2, tich);
            break;
        case 4:
            thuong = num1 / num2;
            du = num1 % num2;
            printf("Thuong cua %d va %d la %d voi so du %d", num1, num2, thuong, du);
            break;
        case 5:
            du = num1 % num2;
            printf("So du cua %d va %d la %d", num1, num2, du);
            break;
        case 6:
            for (int i = 1; i <= num1 && i <= num2; ++i) {
                if (num1 % i == 0 && num2 % i == 0)
                    UCln = i;
            }
            printf("Uoc chung lon nhat cua %d va %d la %d", num1, num2, UCln);
            break;
        case 7:
            for (int i = 1; i <= (num1 * num2); i++) {
                if (i % num1 == 0 && i % num2 == 0) {
                    BCnn = i;
                    break;
                }
            }
            printf("Boi chung nho nhat cua %d va %d la %d", num1, num2, BCnn);
            break;
        case 8:
            printf("Thoat");
            break;
        default:
            printf("Lua chon khong hop le");
    }

    return 0;
}