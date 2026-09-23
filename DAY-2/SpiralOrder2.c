#include <stdio.h>
#include <stdlib.h>

int** generateMatrix(int n)
{
    int** matrix = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++)
        matrix[i] = (int*)malloc(n * sizeof(int));

    int num = 1;
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right)
    {
        // Left to right
        for (int i = left; i <= right; i++)
            matrix[top][i] = num++;

        top++;

        // Top to bottom
        for (int i = top; i <= bottom; i++)
            matrix[i][right] = num++;

        right--;

        // Right to left
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                matrix[bottom][i] = num++;

            bottom--;
        }

        // Bottom to top
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                matrix[i][left] = num++;

            left++;
        }
    }

    return matrix;
}

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int** matrix = generateMatrix(n);

    printf("Spiral Matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}