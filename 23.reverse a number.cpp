#include <stdio.h>

int reverseNumber(int num) {
    int reverse = 0;
    while (num != 0) {
        reverse = reverse * 10 + num % 10;
        num /= 10;
    }
    return reverse;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Reverse of the number: %d\n", reverseNumber(num));

    return 0;
}



