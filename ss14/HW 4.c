#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void print_menu() {
    printf("MENU\n");
    printf("1. Nhập vào mảng\n");
    printf("2. In ra mảng\n");
    printf("3. Sao chép mảng vào mảng khác\n");
    printf("4. Nhập vào mảng khác, đổi chỗ 2 mảng với nhau\n");
    printf("5. Đảo ngược mảng\n");
    printf("6. Nhập vào 1 ký tự, tìm kiếm ký tự đó trong mảng\n");
    printf("7. Thoát\n");
    printf("Lựa chọn của bạn: ");
}

void input_array(char* arr) {
    printf("Nhập vào mảng: ");
    fgets(arr, MAX_SIZE, stdin);
    arr[strlen(arr) - 1] = '\0';  // Loại bỏ ký tự xuống dòng
}

void print_array(const char* arr) {
    printf("Mảng: %s\n", arr);
}
void copy_array(const char* src, char* dest) {
    while (*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}
void swap_arrays(char* arr1, char* arr2) {
    char temp[MAX_SIZE];
    copy_array(arr1, temp);
    copy_array(arr2, arr1);
    copy_array(temp, arr2);
}
void reverse_array(char* arr) {
    int len = strlen(arr);
    for (int i = 0; i < len / 2; i++) {
        char temp = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = temp;
    }
}
void search_char(const char* arr, char c) {
    const char* ptr = arr;
    while (*ptr != '\0') {
        if (*ptr == c) {
            printf("Ký tự '%c' duoc tim thay trong mang.\n", c);
            return;
        }
        ptr++;
    }
    printf("Ky tu '%c' khong duoc tim thay trong mang.\n", c);
}

int main() {
    char arr1[MAX_SIZE] = "", arr2[MAX_SIZE] = "";
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                input_array(arr1);
                break;
            case 2:
                print_array(arr1);
                break;
            case 3:
                copy_array(arr1, arr2);
                printf("Da sao chep mang vao mang khac.\n");
                break;
            case 4:
                printf("Nhap vao mang khac: ");
                fgets(arr2, MAX_SIZE, stdin);
                arr2[strlen(arr2) - 1] = '\0';
                swap_arrays(arr1, arr2);
                printf("Da doi cho 2 mang voi nhau.\n");
                break;
            case 5:
                reverse_array(arr1);
                printf("Da dao nguoc mang.\n");
                break;
            case 6:
                printf("Nhap vao 1 ky tu: ");
                char c = getchar();
                search_char(arr1, c);
                break;
            case 7:
                printf("Thoat.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
                break;
        }
    } while (choice != 7);
    return 0;
}
