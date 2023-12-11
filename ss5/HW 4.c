#include<stdio.h>
int main()
{
    double luongNhanVien;
    printf("luong nhan vien: ");
    scanf("%lf",&luongNhanVien);
    if (luongNhanVien<=5000){
        printf("luong rong cua nhan vien: %.2lf", (0.95)*luongNhanVien);
    }else if (luongNhanVien>=5000&&luongNhanVien<=10000){
        printf("luong rong cua nhan vien: %.2lf",(0.9)*luongNhanVien);
    }else if (luongNhanVien>=10000&&luongNhanVien<=18000){
        printf("luong rong cua nhan vien: %.2lf",(0.85)*luongNhanVien);
    }else if(luongNhanVien>=18000&&luongNhanVien<=32000){
        printf("luong rong cua nhan vien: %.2lf",(0.8)*luongNhanVien);
    }else if(luongNhanVien>=32000&&luongNhanVien<=52000) {
        printf("luong rong cua nhan vien: %.2lf", (0.75) * luongNhanVien);
    }else if(luongNhanVien>=52000&&luongNhanVien<=80000) {
        printf("luong rong cua nhan vien: %.2lf", (0.7) * luongNhanVien);
    }else if(luongNhanVien>=80000) {
        printf("luong rong cua nhan vien: %.2lf", (0.65) * luongNhanVien);
    }
    return 0;
}
