#include <stdio.h>
#include <math.h>

int main() {
    double principal, rate, interest, amount;
    int months, i;
    printf("Nhap vao so tien gui ngan hang ban dau: ");
    scanf("%lf", &principal);
    printf("Nhap vao lai suat nam (%%): ");
    scanf("%lf", &rate);
    printf("Nhap vao so thang gui: ");
    scanf("%d", &months);

    rate = rate / 12 / 100;
    printf("\nThang\tTien gui\tTien lai\n");
    for(i = 1; i <= months; i++) {
        interest = principal * rate;
        principal += interest;
        printf("%d\t%.2lf\t%.2lf\n", i, principal, interest);
    }
    
    printf("\nTong so tien nhan duoc sau %d thang la: %.2lf\n", months, principal);

    return 0;
}
