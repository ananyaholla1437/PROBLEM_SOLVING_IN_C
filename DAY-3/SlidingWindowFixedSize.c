#include <stdio.h>

int maxSum(int arr[],int n,int k){
    int windowSum=0;
    int maxSum=0;
    // first Window
    for(int i=0;i<k;i++){
        windowSum=windowSum+arr[i];
    }
    maxSum=windowSum;
    for(int i=k;i<n;i++){
        windowSum=windowSum+arr[i]-arr[i-k];
        if(windowSum>maxSum){
            maxSum=windowSum;
        }
    }
    return maxSum;
}

int main(){
    int arr[]={2,1,5,1,3,2};
    int n=6;
    int k=3;
    int result = maxSum(arr, n, k);
    printf("Maximum Sum = %d\n", result);
    return 0;
}
