#include <stdio.h>
#include <string.h>

int main() {
    char str[100], ch, ch1, ch2;
    int choice;
    do {
        printf("MENU\n");
        printf("1. Nhap vao chuoi ky tu\n");
        printf("2. In ra noi dung chuoi\n");
        printf("3. Nhap vao 1 ky tu, dem so lan xuat hien ky tu trong chuoi\n");
        printf("4. Nhap vao 2 ky tu, thay the cac ky tu thu 2 trong chuoi thanh ky tu thu nhat\n");
        printf("5. Nhap vao 1 ky tu, xoa bo cac ky tu trong chuoi\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Nhap chuoi: ");
                fgets(str, 100, stdin);
                str[strlen(str) - 1] = '\0';
                break;
            case 2:
                printf("Noi dung chuoi: %s\n", str);
                break;
            case 3:
                printf("Nhap ky tu: ");
                scanf("%c", &ch);
                getchar();
                int count = 0;
                for (int i = 0; i < strlen(str); i++) {
                    if (str[i] == ch) count++;
                }
                printf("So lan xuat hien ky tu '%c' trong chuoi: %d\n", ch, count);
                break;
            case 4:
                printf("Nhap 2 ky tu: ");
                scanf("%c %c", &ch1, &ch2);
                getchar();
                for (int i = 0; i < strlen(str); i++) {
                    if (str[i] == ch2) str[i] = ch1;
                }
                printf("Chuoi sau khi thay the: %s\n", str);
                break;
            case 5:
                printf("Nhap ky tu: ");
                scanf("%c", &ch);
                getchar();
                int j = 0;
                for (int i = 0; i < strlen(str); i++) {
                    if (str[i] != ch) str[j++] = str[i];
                }
                str[j] = '\0';
                printf("Chuoi sau khi xoa: %s\n", str);
                break;
            case 6:
                printf("Thoat\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 6);
    return 0;
}