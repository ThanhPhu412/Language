#include<stdio.h>
#include<math.h>
int main()
{
    float delta,a,b,c;

    printf("a: ");
    scanf("%f", &a);
    printf("b: ");
    scanf("%f", &b);
    printf("c: ");
    scanf("%f",&c);
    delta=pow(b,2)-4*a*c;
    if (delta<0){
        printf("phuong trinh vo nghiem");
    }else if (delta==0){
        printf("phuong trinh co nghiem kep x1= x2= %.2f",-b/2*a);
    }else if(delta>0)
        printf("phuong trinh co 2 nghiem phan biet x1= %.2f, x2= %.2f",(-b+sqrt(delta))/2*a, (-b-sqrt(delta))/2*a);

    return 0;
}