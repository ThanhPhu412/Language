#include <stdio.h>

int main() {
    float m,l,e;
    printf("Nhap diem Toan: ");
    scanf("%f", &m);
    printf("Nhap diem Van: ");
    scanf("%f", &l);
    printf("Nhap diem Anh: ");
    scanf("%f", &e);
    printf("Tong diem la: %.2f\n",m+l+e);
    printf("Diem trung binh la: %.2f\n",(m+l+e)/3);
    return 0;
}
