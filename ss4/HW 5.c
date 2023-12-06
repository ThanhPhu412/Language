#include<stdio.h>
int main()
{
    int day, month, year;
    printf("day: ");
    scanf("%d",&day);
    printf("month: ");
    scanf("%d",&month);
    printf("year: ");
    scanf("%d",&year);
    if (year<0 || ( month<0 || month>13)|| (day<1||day>31)) {
        printf("ko hop le");
    }
    else {
        int daysInMonth;
        switch (month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                daysInMonth = 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                daysInMonth = 30;
                break;
            case 2:
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                    daysInMonth = 29;
                } else daysInMonth = 28;
                break;
        }
        if (day<=daysInMonth){
            printf("hop le");
        }else printf("khong hop le");
    }
    return 0;
}

