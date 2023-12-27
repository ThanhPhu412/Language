#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    double income;
    int population;
    double literacyRate;
} ThanhPho;

int main(void) {
    int n, i, thuNhap = 0, hocVan = 0;

    printf("Nhap so thanh pho: ");
    scanf("%d", &n);

    ThanhPho cities[n];

    for(i = 0; i < n; i++) {
        printf("Nhap chi tiet thanh pho thu %d:\n", i);

        printf("Nhap ten thanh pho: ");
        getchar();
        gets(cities[i].name);

        printf("Nhap tong thu nhap: ");
        scanf("%lf", &cities[i].income);

        printf("Nhap tong so dan: ");
        scanf("%d", &cities[i].population);

        printf("Nhap ti le biet doc viet: ");
        scanf("%lf", &cities[i].literacyRate);

        if(cities[i].income > cities[thuNhap].income) {
            thuNhap = i;
        }

        if(cities[i].literacyRate > cities[hocVan].literacyRate) {
            hocVan = i;
        }
    }

    printf("\nThanh pho co tong thu nhap cao nhat: %s\n", cities[thuNhap].name);
    printf("Thanh pho co ti le biet doc viet cao nhat: %s\n", cities[hocVan].name);

}