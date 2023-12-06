#include <stdio.h>
int main()
{
    double oldnum, newnum, difference;
    printf("oldnum: ");
    scanf("%lf", &oldnum);
    printf("newnum: ");
    scanf("%lf", &newnum);
    difference=newnum-oldnum;
    if (difference >= 0 && difference < 50){
        printf("cost=10.000");
    }else if (difference >= 50 && difference < 100){
        printf("cost=15.000");
    } else if (difference >= 100 && difference < 150){
        printf("cost=20.000");
    }else if(difference >= 150 && difference < 200){
        printf("cost=25.000");
    }else if(200<=difference){
        printf("cost=30.000");
    }
    return 0;
}
