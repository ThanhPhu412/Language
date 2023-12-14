#include <stdio.h>
int main(){
    short data1[2][10]={
            {5,6,7,8,9,10,11,12,13,14},
            {15,16,17,18,19,20,21,22,23,24},
    };
    short data2[2][10];
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 10; j++) {
            data2[i][j] = data1[i][j];
        }
    }
//Kiểm tra mảng mới
    printf("mảng data2 sau khi copy: \n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 10; j++) {
            printf("%d ", data2[i][j]);
        }
        printf("\n");
    }
}