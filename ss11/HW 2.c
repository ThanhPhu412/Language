#include <stdio.h>

void printArray(int arr[10][10], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void sortRow(int arr[10][10], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            for (int k = 0; k < m - j - 1; k++) {
                if (arr[i][k] > arr[i][k + 1]) {
                    int temp = arr[i][k];
                    arr[i][k] = arr[i][k + 1];
                    arr[i][k + 1] = temp;
                }
            }
        }
    }
}

void sortColumn(int arr[10][10], int n, int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = 0; k < n - j - 1; k++) {
                if (arr[k][i] < arr[k + 1][i]) {
                    int temp = arr[k][i];
                    arr[k][i] = arr[k + 1][i];
                    arr[k + 1][i] = temp;
                }
            }
        }
    }
}

int main() {
    int arr[10][10], n, m, choice;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &n, &m);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    do {
        printf("\nMENU\n");
        printf("1. Print the array\n");
        printf("2. Sort the array by row in ascending order\n");
        printf("3. Sort the array by column in descending order\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printArray(arr, n, m);
                break;
            case 2:
                sortRow(arr, n, m);
                break;
            case 3:
                sortColumn(arr, n, m);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}
