#include <stdio.h>

int main() {
    int num1,num2,num3;
    printf("So thu nhat la:");
    scanf("%d",&num1);
    printf("So thu hai la:");
    scanf("%d",&num2);
    printf("So thu ba la:");
    scanf("%d",&num3);
    int max =num1, min=num1;
            if(max<num2){max=num2;}
            if(max<num3){max=num3;}
            if(min>num2){min=num2;}
            if(min>num3){min=num3;}
            printf ("Mã la : - Min la : %d %d",max, min);
            return 0;




}
