#include <stdio.h>
#include <stdlib.h>

void productExceptSelf(int nums[], int n, int result[])
{
    int prefix = 1;

    // Product of elements on the left
    for (int i = 0; i < n; i++)
    {
        result[i] = prefix;
        prefix = prefix * nums[i];
    }

    int suffix = 1;

    // Product of elements on the right
    for (int i = n - 1; i >= 0; i--)
    {
        result[i] = result[i] * suffix;
        suffix = suffix * nums[i];
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];
    int result[n];

    printf("Enter the elements: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    productExceptSelf(nums, n, result);

    printf("Product except self: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", result[i]);
    }

    return 0;
}