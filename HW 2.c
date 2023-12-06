#include <stdio.h>

int main() {
    float r;
    const float Pi = 3.14;
    printf ("Nhap r ");
    scanf("%f", &r);
    printf("Dien tich hinh tron %.2f\n", Pi*r*r);
    printf("Chu vi hinh tron %.2f\n", Pi*2*r);
    return 0;
}
