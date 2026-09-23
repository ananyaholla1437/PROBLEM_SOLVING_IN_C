#include <stdio.h>
int trap(int *height, int heightSize)
{
    int left = 0;
    int right = heightSize - 1;

    int leftMax = 0;
    int rightMax = 0;
    int water = 0;

    while (left < right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] >= leftMax)
            {
                leftMax = height[left];
            }
            else
            {
                water = water + (leftMax - height[left]);
            }
            left++;
        }
        else
        {
            if (height[right] >= rightMax)
            {
                rightMax = height[right];
            }
            else
            {
                water = water + (rightMax - height[right]);
            }
            right--;
        }
    }
    return water;
}
int main()
{
    int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int heightSize = 12;
    int result = trap(height, heightSize);
    printf("Trapped Rain Water = %d\n", result);
    return 0;
}