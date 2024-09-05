#include <stdio.h>

// Function to multiply two matrices using Strassen's algorithm
void strassenMultiply(int A[10][10], int B[10][10], int C[10][10], int n) {
    int mid = n / 2;

    // Base case: 1x1 matrix
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    // Declare temporary matrices
    int A11[10][10], A12[10][10], A21[10][10], A22[10][10];
    int B11[10][10], B12[10][10], B21[10][10], B22[10][10];
    int M1[10][10], M2[10][10], M3[10][10], M4[10][10], M5[10][10], M6[10][10], M7[10][10];

    // Split matrices into quarters
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][mid + j];
            A21[i][j] = A[mid + i][j];
            A22[i][j] = A[mid + i][mid + j];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][mid + j];
            B21[i][j] = B[mid + i][j];
            B22[i][j] = B[mid + i][mid + j];
        }
    }

    // Calculate intermediate matrices
    strassenMultiply(A11, B11, M1, mid);
    strassenMultiply(A12, B21, M2, mid);
    strassenMultiply(A11, B12, M3, mid);
    strassenMultiply(A12, B22, M4, mid);
    strassenMultiply(A21, B11, M5, mid);
    strassenMultiply(A22, B21, M6, mid);
    strassenMultiply(A21, B12, M7, mid);

    // Calculate final matrices
    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            C[i][j] = M1[i][j] + M2[i][j] + M4[i][j] - M3[i][j] + M6[i][j];
            C[i][mid + j] = M1[i][j] + M3[i][j];
            C[mid + i][j] = M5[i][j] + M6[i][j];
            C[mid + i][mid + j] = M2[i][j] + M4[i][j] + M5[i][j] + M7[i][j];
        }
    }
}

int main() {
    int A[10][10], B[10][10], C[10][10], n;

    printf("Enter the size of the matrices (power of 2): ");
    scanf("%d", &n);

    printf("Enter matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter matrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    strassenMultiply(A, B, C, n);

    printf("Resultant matrix C:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}


