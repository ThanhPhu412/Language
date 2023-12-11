#include <stdio.h>

int main() {
    int num, originalNum, remainder, result = 0;
    printf("Cac so Armstrong co ba chu so la:\n");

    for(num = 100; num < 1000; num++) {
        originalNum = num;
        result = 0;

        while (originalNum != 0) {
            remainder = originalNum % 10;
            result += remainder * remainder * remainder;
            originalNum /= 10;
        }

        if (result == num) {
            printf("%d\n", num);
        }
    }

    return 0;
}
