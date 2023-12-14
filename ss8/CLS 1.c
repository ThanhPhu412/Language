#include<stdio.h>
int main(){
    int x, y;
    printf("nhap do dai(so mang 1 chieu) tron mang 2 chieu: ");
    scanf("%d", &y);
    printf("Nhap do dai so phan tu trong mang 1 chieu: ");
    scanf("%d", &x);

    int array[y][x];
    printf("nhap phan tu: ");
    for (int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            scanf("%d", &array[i][j]);
    };
    };
    printf("Mang vua nhap: ");
    for (int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            printf("%d", array[i][j]);
        }
        printf("\n");
    }
}
