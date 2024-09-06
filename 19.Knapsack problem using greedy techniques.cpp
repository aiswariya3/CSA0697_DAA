#include <stdio.h>

void knapsack(int w, int wt[], int val[], int n) {
    int i, j;
    float max = 0.0;
    int res[n];

    for (i = 0; i < n; i++) {
        res[i] = 0;
    }

    for (i = 0; i < n; i++) {
        if (wt[i] <= w) {
            res[i] = 1;
            w -= wt[i];
            max += val[i];
        }
    }

    printf("Maximum value: %f\n", max);
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int wt[n], val[n];
    printf("Enter the weights and values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &wt[i], &val[i]);
    }

    int w;
    printf("Enter the maximum weight: ");
    scanf("%d", &w);

    knapsack(w, wt, val, n);

    return 0;
}

