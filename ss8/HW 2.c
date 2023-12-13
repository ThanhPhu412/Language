#include <stdio.h>

int main() {
    int row, col;
    printf("Nhập số hàng của mảng: ");
    scanf("%d", &row);
    printf("Nhập số cột của mảng: ");
    scanf("%d", &col);
    int arr[row][col];

    printf("Nhập giá trị các phần tử của mảng: ");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int sum = 0;
    printf("Các phần tử có giá trị chẵn trong mảng là: ");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(arr[i][j] % 2 == 0) {
                printf("%d ", arr[i][j]);
                sum += arr[i][j];
            }
        }
    }

    printf("\nTổng các phần tử có giá trị chẵn trong mảng là: %d\n", sum);

    return 0;
}
