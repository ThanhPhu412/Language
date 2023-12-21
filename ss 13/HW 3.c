#include <stdio.h>
#include <string.h>

int main() {
    char str[100], ch[100];
    int freq[100] = {0}, len, i, j;
    printf("Nhap vao chuoi: ");
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0';
    len = strlen(str);
    for (i = 0; i < len; i++) {
        ch[i] = str[i];
        freq[i] = -1;
    }
    for (i = 0; i < len; i++) {
        int count = 1;
        for (j = i + 1; j < len; j++) {
            if (str[i] == str[j]) {
                count++;
                freq[j] = 0;
            }
        }
        if (freq[i] != 0) {
            freq[i] = count;
        }
    }
    printf("So lan xuat hien cua moi ky tu trong chuoi:\n");
    for (i = 0; i < len; i++) {
        if (freq[i] != 0) {
            printf("%c: %d\n", ch[i], freq[i]);
        }
    }
    return 0;
}