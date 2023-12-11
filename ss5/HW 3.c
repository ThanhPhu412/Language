#include <stdio.h>
int main()
{
    float soPhut;
    printf("so phut goi: ");
    scanf("%f",&soPhut);
    if (soPhut<=50) {
        printf("Tien: %f", 25.000 + 50 * 600);
    }else if(soPhut<=200){
        printf("Tien: %f",25.000+50*600+(soPhut-50)*400);
    }else if(soPhut<=400){
        printf("Tien: %f",25.000+50*600+150*400+(soPhut-200)*200);
    }else if(soPhut>400) {
        printf("Tien: %f", 25.000 + 50 * 600 + 150 * 400 + 200 * 200 + (soPhut - 400) * 100);
    }
    return 0;
}
