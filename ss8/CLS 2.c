#include <stdio.h>
int main(){
    int data1[10]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int data2[10];
    for(int i=0; i<10; i++){
        data2[i]=data1[i];
    }
    for(int i=0; i<10; i++){
        printf("%d", data2[i]);
    }

}
