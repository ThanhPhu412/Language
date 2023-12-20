#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[100], n, i, choice;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do {
        printf("\nMENU\n");
        printf("1. Print the array\n");
        printf("2. Sort the array in descending order using Insertion Sort\n");
        printf("3. Sort the array in ascending order using Selection Sort\n");
        printf("4. Sort the array in descending order using Bubble Sort\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printArray(arr, n);
                break;
            case 2:
                insertionSort(arr, n);
                printArray(arr, n);
                break;
            case 3:
                selectionSort(arr, n);
                printArray(arr, n);
                break;
            case 4:
                bubbleSort(arr, n);
                printArray(arr, n);
                break;
            case 5:
                printf("Exiting the program!");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.");
        }
    } while(choice != 5);

    return 0;
}
