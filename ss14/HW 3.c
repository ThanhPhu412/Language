#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    char *ptr1 = str1, *ptr2 = str2;
    int len1, len2;

    printf("Nhap chuoi thu nhat: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Nhap chuoi thu hai: ");
    fgets(str2, sizeof(str2), stdin);

    len1 = strlen(ptr1) - 1;
    len2 = strlen(ptr2) - 1;

    printf("Do dai chuoi thu nhat: %d\n", len1);
    printf("Do dai chuoi thu hai: %d\n", len2);

    if (len1 > len2) {
        printf("Chuoi thu nhat co do dai lon hon.\n");
    } else if (len1 < len2) {
        printf("Chuoi thu hai co do dai lon hon.\n");
    } else {
        printf("Hai chuoi co do dai bang nhau.\n");
    }
    return 0;
}
