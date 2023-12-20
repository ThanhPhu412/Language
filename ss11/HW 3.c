#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[100];
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    printf("Enter the elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int choice, target;
    do {
        printf("\nMENU\n");
        printf("1. Print array\n");
        printf("2. Linear search\n");
        printf("3. Binary search\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printArray(arr, size);
                break;
            case 2:
                printf("Enter the value to search: ");
                scanf("%d", &target);
                int result = linearSearch(arr, size, target);
                if (result != -1) {
                    printf("Element found at index %d\n", result);
                } else {
                    printf("Element not found in the array\n");
                }
                break;
            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &target);
                result = binarySearch(arr, 0, size - 1, target);
                if (result != -1) {
                    printf("Element found at index %d\n", result);
                } else {
                    printf("Element not found in the array\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
