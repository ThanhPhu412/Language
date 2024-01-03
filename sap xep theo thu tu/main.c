#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct SinhVien {
    char ten[50];
    char lop[10];
    char ngaySinh[11];
    float gpa;
};
int soSanh(const void *a, const void *b) {
    const struct SinhVien *sv1 = (const struct SinhVien *)a;
    const struct SinhVien *sv2 = (const struct SinhVien *)b;
    return (sv2->gpa > sv1->gpa) - (sv2->gpa < sv1->gpa);
}

int main() {
    FILE *inputFile, *outputFile;
    struct SinhVien danhSach[100];
    int soLuongSinhVien = 0;
    inputFile = fopen("sinhvien.txt", "r");
    if (inputFile == NULL) {
        perror("khong the mo file input");
        exit(EXIT_FAILURE);
    }
    while (fscanf(inputFile, "%49[^,],%9[^,],%10[^,],%f\n",
                  danhSach[soLuongSinhVien].ten,
                  danhSach[soLuongSinhVien].lop,
                  danhSach[soLuongSinhVien].ngaySinh,
                  &danhSach[soLuongSinhVien].gpa) == 4) {
        soLuongSinhVien++;
    }
    qsort(danhSach, soLuongSinhVien, sizeof(struct SinhVien), soSanh);

    outputFile = fopen("sinhvien_out.txt", "w");
    if (outputFile == NULL) {
        perror("khong the mo file output");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < soLuongSinhVien; i++) {
        fprintf(outputFile, "%s,%s,%s,%.2f\n",
                danhSach[i].ten,
                danhSach[i].lop,
                danhSach[i].ngaySinh,
                danhSach[i].gpa);
    }
    fclose(inputFile);
    fclose(outputFile);

    printf("sap xep va ghi cac sinh vien thanh cong.\n");

    return 0;
}
