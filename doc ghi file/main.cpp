#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void chuanHoaTen(char *ten) {
    int i, j = 0;
    int len = strlen(ten);

    for (i = 0; i < len; i++) {
        if (ten[i] != ' ' || (i > 0 && ten[i - 1] != ' ')) {
            ten[j++] = ten[i];
        }
    }
    ten[j] = '\0';

    for (i = 0; i < j; i++) {
        if (i == 0 || ten[i - 1] == ' ') {
            ten[i] = toupper(ten[i]);
        } else {
            ten[i] = tolower(ten[i]);
        }
    }
}

int main() {
    FILE *inputFile, *outputFile;
    char buffer[256];
    int soLuongSinhVien, i;

    if ((inputFile = fopen("sinhvien.txt", "r")) == NULL) {
        perror("khong the mo file input");
        exit(EXIT_FAILURE);
    }

    fscanf(inputFile, "%d\n", &soLuongSinhVien);

    if ((outputFile = fopen("sinhvien_out.txt", "w")) == NULL) {
        perror("khong the mo file output");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    fprintf(outputFile, "%d\n", soLuongSinhVien);

    for (i = 0; i < soLuongSinhVien; i++) {
        fgets(buffer, sizeof(buffer), inputFile);
        buffer[strcspn(buffer, "\n")] = 0;
        chuanHoaTen(buffer);
        fprintf(outputFile, "%s\n", buffer);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Chuyen hoa ten thanh cong va luu vao sinhvien_out.txt\n");

    return  0;
}
