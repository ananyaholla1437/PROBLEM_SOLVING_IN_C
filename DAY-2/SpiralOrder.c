#include <stdio.h>

void spiralOrder(int matrix[][100], int m, int n) {
    int top = 0;
    int bottom = m - 1;
    int left = 0;
    int right = n - 1;

    while (top <= bottom && left <= right) {

        // Left -> Right
        for (int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++;

        // Top -> Bottom
        for (int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;

        // Right -> Left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        // Bottom -> Top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }
}

int main() {
    int m = 3, n = 3;
    int matrix[100][100];

    // Input matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Spiral matrix: ");

    spiralOrder(matrix, m, n);

    return 0;
}