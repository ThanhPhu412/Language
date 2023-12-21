#include <stdio.h>
#include <string.h>

int main() {
    char str[100], temp[100];
    int i, j, maxLen = 0, len = 0, start = 0;
    printf("Nhap vao chuoi: ");
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0';
    for (i = 0; i < strlen(str); i++) {
        for (j = 0; j < len; j++) {
            if (temp[j] == str[i]) {
                if (len > maxLen) {
                    maxLen = len;
                    start = i - len;
                }
                len = 0;
                break;
            }
        }
        if (j == len) {
            temp[len++] = str[i];
        }
    }
    if (len > maxLen) {
        maxLen = len;
        start = i - len;
    }
    printf("Chuoi phan biet co do dai lon nhat la %d: ", maxLen);
    for (i = start; i < start + maxLen; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}