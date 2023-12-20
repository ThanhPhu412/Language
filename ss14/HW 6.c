#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

void print_menu() {
    printf("MENU\n");
    printf("1. Nhập vào chuỗi\n");
    printf("2. In ra chuỗi\n");
    printf("3. Sao chép chuỗi vào một chuỗi khác\n");
    printf("4. Nhập vào chuỗi khác, tiến hành thêm chuỗi đó vào chuỗi ban đầu\n");
    printf("5. Nhập vào chuỗi khác, so sánh chuỗi đó với chuỗi ban đầu\n");
    printf("6. In ra chuỗi đảo ngược\n");
    printf("7. Thoát\n");
    printf("Lựa chọn của bạn: ");
}

int main() {
    char *str = malloc(MAX_LEN * sizeof(char));
    char *str2 = malloc(MAX_LEN * sizeof(char));
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);
        getchar(); // remove newline from input

        switch(choice) {
            case 1:
                printf("Nhập vào chuỗi: ");
                fgets(str, MAX_LEN, stdin);
                str[strlen(str) - 1] = '\0'; // remove newline from input
                break;
            case 2:
                printf("Chuỗi của bạn: %s\n", str);
                break;
            case 3:
                strcpy(str2, str);
                printf("Chuỗi đã được sao chép: %s\n", str2);
                break;
            case 4:
                printf("Nhập vào chuỗi khác: ");
                fgets(str2, MAX_LEN, stdin);
                str2[strlen(str2) - 1] = '\0'; // remove newline from input
                strcat(str, str2);
                printf("Chuỗi sau khi thêm: %s\n", str);
                break;
            case 5:
                printf("Nhập vào chuỗi khác: ");
                fgets(str2, MAX_LEN, stdin);
                str2[strlen(str2) - 1] = '\0'; // remove newline from input
                if(strcmp(str, str2) == 0)
                    printf("Chuỗi giống nhau.\n");
                else
                    printf("Chuỗi khác nhau.\n");
                break;
            case 6:
                for(int i = strlen(str) - 1; i >= 0; i--)
                    printf("%c", str[i]);
                printf("\n");
                break;
            case 7:
                printf("Thoát chương trình.\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ. Vui lòng thử lại.\n");
        }
    } while(choice != 7);

    free(str);
    free(str2);

    return 0;
}
