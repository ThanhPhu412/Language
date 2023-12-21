#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int choice;
    do {
        printf("MENU\n");
        printf("1. Nhap vao chuoi ky tu\n");
        printf("2. In ra do dai chuoi va noi dung chuoi vua nhap\n");
        printf("3. In ra chuoi dao nguoc\n");
        printf("4. In ra so luong chu cai trong chuoi\n");
        printf("5. In ra so luong chu so trong chuoi\n");
        printf("6. In ra so luong ky tu dac biet trong chuoi\n");
        printf("7. Thoat\n");
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
                printf("Do dai chuoi: %lu\n", strlen(str));
                printf("Noi dung chuoi: %s\n", str);
                break;
            case 3:
                printf("Chuoi dao nguoc: ");
                for (int i = strlen(str) - 1; i >= 0; i--) {
                    printf("%c", str[i]);
                }
                printf("\n");
                break;
            case 4: {
                int count = 0;
                for (int i = 0; i < strlen(str); i++) {
                    if (isalpha(str[i])) count++;
                }
                printf("So luong chu cai trong chuoi: %d\n", count);
                break;
            }
            case 5: {
                int count = 0;
                for (int i = 0; i < strlen(str); i++) {
                    if (isdigit(str[i])) count++;
                }
                printf("So luong chu so trong chuoi: %d\n", count);
                break;
            }
            case 6: {
                int count = 0;
                for (int i = 0; i < strlen(str); i++) {
                    if (!isalnum(str[i]) && str[i] != ' ') count++;
                }
                printf("So luong ky tu dac biet trong chuoi: %d\n", count);
                break;
            }
            case 7:
                printf("Thoat\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 7);
    return 0;
}