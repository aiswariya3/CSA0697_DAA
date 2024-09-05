#include <stdio.h>
#include <string.h>

void copyString(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int main() {
    char src[100], dest[100];

    printf("Enter a string: ");
    scanf("%s", src);

    copyString(dest, src);

    printf("Copied string: %s", dest);

    return 0;
}

