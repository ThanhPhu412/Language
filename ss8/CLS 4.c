#include <stdio.h>
#include <string.h>
int main(void){
    int src[2][5]= {
            {1, 2, 3, 4, 5},
            {6, 7, 8, 9, 10},
    };
    int dest[2][5];
    memcpy((void*)dest, (void*)src, sizeof(src));
    for (int i=0; i<2; i++){
        for(int j=0; j<5; j++){
            printf("%d ", dest[i][j]);
        }
    }

}