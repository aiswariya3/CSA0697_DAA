#include <stdio.h>

void generatePrimes(int n) {
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = 1;
    }

    for (int i = 2; i * i <= n; i++) {
        if (arr[i] == 1) {
            for (int j = i * i; j <= n; j += i) {
                arr[j] = 0;
            }
        }
    }

    printf("Prime numbers: ");
    for (int i = 2; i <= n; i++) {
        if (arr[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    generatePrimes(n);

    return 0;
}


