#include<stdio.h>
int main()
{
    int doanhThuBanHang;
    printf("doanh thu ban hang: ");
    scanf("%d",&doanhThuBanHang);
    if(doanhThuBanHang<=100){
        printf("hoaHongDaiLy=5%");
    }else if(doanhThuBanHang<=300){
        printf("hoaHongDaiLy=10%");
    }else if(doanhThuBanHang>300){
        printf("hoaHongDaiLy=20%");
    }
    return 0;
}
