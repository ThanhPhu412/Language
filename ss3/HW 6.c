#include <stdio.h>

int main() {
    int y,yn, tuoi;
    printf("Nhap nam sinh: ");
    scanf ("%d",&y);
    printf("Nhap nam hien tai:");
    scanf ("%d",&yn);
    printf("Tuoi", yn-y==tuoi);
    if(tuoi%2==0){printf("chan");}
    else { printf("le");}
    return 0;
}
