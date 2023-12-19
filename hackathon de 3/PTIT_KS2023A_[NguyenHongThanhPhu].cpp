#include <stdio.h>
#include <stdlib.h>

int *arr = NULL;
int n = 0;

void displayMenu() {
    printf("\n************************MENU**************************\n");
    printf("1. Nhap gia tri n phan tu cua mang (n nhap tu ban phim)\n");
    printf("2. In gia tri cac phan tu trong mang\n");
    printf("3. Tinh tong cac phan tu chia het cho 2 va 3 trong mang\n");
    printf("4. In ra gia tri phan tu lon nhat va nho nhat trong mang\n");
    printf("5. Su dung thuat toan sap xep chen sap xep mang tang dan\n");
    printf("6. Tinh tong cac phan tu la so nguyen to trong mang\n");
    printf("7. Sap xep cac phan tu le chia het cho 5 o dau mang, chan chia het cho 5 o cuoi mang\n");
    printf("8. Nhap gia tri m tu ban phim, chen gia tri m vao mang (sap xep tang dan)\n");
    printf("9. Thoat\n");
    printf("*******************************************************\n");
}

void inputArray() {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    printf("Nhap gia tri cho tung phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

void printArray() {
    printf("Cac phan tu trong mang la:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sumDivisibleBy2And3() {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0 && arr[i] % 3 == 0) {
            sum += arr[i];
        }
    }
    return sum;
}

int findMaxValue() {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMinValue() {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void insertionSort() {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int isPrime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int sumPrimeNumbers() {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            sum += arr[i];
        }
    }
    return sum;
}

void customSort() {
    int oddIndex = 0;
    int evenIndex = n - 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 1 && arr[i] % 5 == 0) {
            arr[oddIndex++] = arr[i];
        } else if (arr[i] % 2 == 0 && arr[i] % 5 == 0) {
            arr[evenIndex--] = arr[i];
        }
    }
}

void insertAndSort(int m) {
    arr[n++] = m;
    insertionSort();
}

void freeMemory() {
    free(arr);
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Chon chuc nang (1-9): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray();
                break;
            case 2:
                printArray();
                break;
            case 3:
                printf("Tong cac phan tu chia het cho 2 va 3: %d\n", sumDivisibleBy2And3());
                break;
            case 4:
                printf("Gia tri lon nhat trong mang: %d\n", findMaxValue());
                printf("Gia tri nho nhat trong mang: %d\n", findMinValue());
                break;
            case 5:
                insertionSort();
                printf("Mang sau khi sap xep tang dan: ");
                printArray();
                break;
            case 6:
                printf("Tong cac so nguyen to trong mang: %d\n", sumPrimeNumbers());
                break;
            case 7:
                customSort();
                printf("Mang sau khi sap xep theo yeu cau: ");
                printArray();
                break;
            case 8:
                int m;
                printf("Nhap gia tri m: ");
                scanf("%d", &m);
                insertAndSort(m);
                printf("Mang sau khi chen gia tri m va sap xep tang dan: ");
                printArray();
                break;
            case 9:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 9);


    return 0;
}
