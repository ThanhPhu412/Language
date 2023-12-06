#include<stdio.h>
int main() {
    int year, month;
    printf("year: ");
    scanf("%d", &year);
    printf("month: ");
    scanf("%d", &month);

    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("31 days");
            break;
        case 4:
        case 6:
        case 9 :
        case 11:
            printf("30 days");
        case 2:
            if (year % 4 == 0 && year % 100 != 0) {
                printf("nam nhuan co 29 ngay");
            } else printf("khong nhuan co 28 ngay");
            break;
        default: printf("du lieu sai");
            return 0;
    }
}