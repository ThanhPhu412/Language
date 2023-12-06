#include <stdio.h>
int main()
{
    int num1,num2,num3,num4,min,max,temp1,temp2;
    printf("num1: ");
    scanf("%d",&num1);
    printf("num2: ");
    scanf("%d",&num2);
    printf("num3: ");
    scanf("%d",&num3);
    printf("num4: ");
    scanf("%d",&num4);
    max=(num1>num2&&num1>num3&&num1>num4)?num1:(num2>num3&&num2>num4)?num2:(num3>num4)?num3:num4;
    min=(num1<num2&&num1<num3<num4)?num1:(num2<num3&&num2<num4)?num2:(num3<num4)?num3:num4;
    if (num1<max && num1>min){
        temp1=num1;
    }else if (num2<max&&num2>min){
        temp1=num2;
    }else if (num3<max&&num3>min){
        temp1=num3;
    }else temp1=num4;
    temp2 = (num1 != max && num1 != min) ? num1 :(num2 != max && num2 != min) ? num2 :(num3 != max && num3 != min) ? num3 :num4;
    printf("giamdan: %d%d%d%d", max,temp1,temp2,min);
    return 0;
}
