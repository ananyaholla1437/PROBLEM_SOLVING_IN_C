#include <stdio.h>

int shipWithinDays(int* weights, int weightsSize, int days)
{
    int low = 0, high = 0;

    for (int i = 0; i < weightsSize; i++)
    {
        if (weights[i] > low)
            low = weights[i];

        high += weights[i];
    }

    while (low < high)
    {
        int mid = low + (high - low) / 2;
        int day = 1;
        int sum = 0;

        for (int i = 0; i < weightsSize; i++)
        {
            if (sum + weights[i] > mid)
            {
                day++;
                sum = 0;
            }

            sum += weights[i];
        }

        if (day <= days)
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int main()
{
    int weights[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    int n = sizeof(weights) / sizeof(weights[0]);

    int result = shipWithinDays(weights, n, days);

    printf("Minimum capacity = %d\n", result);

    return 0;
}