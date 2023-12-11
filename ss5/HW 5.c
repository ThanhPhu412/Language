#include<stdio.h>
int main()
{
    int ngay, thang;
    printf("ngay sinh: ");
    scanf("%d",&ngay);
    printf("thang sinh: ");
    scanf("%d",&thang);
    if((thang==3&&ngay>=21)||(thang==4&&ngay<=20)){
        printf("Bach duong");
    }else if((thang==4&&ngay>=21)||(thang==5&&ngay<=20)) {
        printf("kim nguu");
    }else if((thang==5&&ngay>=21)||(thang==6&&ngay<=21)) {
        printf("song tu");
    }else if((thang==4&&ngay>=22)||(thang==5&&ngay<=22)) {
        printf("cu giai");
    }else if((thang==7&&ngay>=23)||(thang==8&&ngay<=22)) {
        printf("su tu");
    }else if((thang==8&&ngay>=23)||(thang==9&&ngay<=22)) {
        printf("xu nu");
    }else if((thang==9&&ngay>=23)||(thang==10&&ngay<=23)) {
        printf("thien binh");
    }else if((thang==10&&ngay>=24)||(thang==11&&ngay<=22)) {
        printf("bo cap");
    }else if((thang==11&&ngay>=23)||(thang==12&&ngay<=21)) {
        printf("nhan ma");
    }else if((thang==12&&ngay>=22)||(thang==1&&ngay<=19)) {
        printf("ma ket");
    }else if((thang==1&&ngay>=20)||(thang==2&&ngay<=18)) {
        printf("bao binh");
    }else if((thang==2&&ngay>=19)||(thang==3&&ngay<=20)) {
        printf("song ngu");
    }
return 0;
}
