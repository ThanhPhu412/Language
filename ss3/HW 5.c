#include <stdio.h>

int main() {
    int thousandDigit, hundredDigit, dozenDigit, unitDigit;
    printf("Nhap so hang nghin");
    scanf("%d", &thousandDigit);
    printf("Nhap so hang tram");
    scanf("%d", &hundredDigit);
    printf("Nhap so hang chuc");
    scanf("%d", &dozenDigit);
    printf("Nhap so hang don vi");
    scanf("%d", &unitDigit);
    printf("Tong cac chu so %d %d %d %d", thousandDigit + hundredDigit + dozenDigit + unitDigit);
    printf("Chuoi dao nguoc %d %d %d %d", unitDigit, dozenDigit, hundredDigit, thousandDigit);
    return 0;
}