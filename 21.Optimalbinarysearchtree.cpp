#include <stdio.h>

int optimalBST(int keys[], int freq[], int n) {
    int cost[n + 1][n + 1];

    for (int i = 0; i <= n; i++) {
        cost[i][i] = freq[i];
    }

    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length + 1; i++) {
            int j = i + length - 1;
            cost[i][j] = 9999;
            for (int r = i; r <= j; r++) {
                int c = cost[i][r - 1] + cost[r + 1][j] + freq[r];
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    int keys[] = {10, 20, 30, 40, 50};
    int freq[] = {34, 8, 50, 16, 22};
    int n = sizeof(keys) / sizeof(keys[0]);

    printf("Cost of Optimal BST: %d\n", optimalBST(keys, freq, n));

    return 0;
}
