#include <stdio.h>
#include <math.h>
int LongestWindow(int days[],int n,int k){
    int left=0;
    int right=0;
    int maxLen=0;
    for(int right=0;right<n;right++){
        if(days[right]-days[left]>k){
            left++;
        }
        int len=right-left+1;
        if(len>maxLen){
            maxLen=len;
        }
    }
return maxLen;

}
int main(){
    int days[]={1,3,5,7,9};
    int n=sizeof(days)/sizeof(int);
    int k=4;
    int result = LongestWindow(days, n, k);
    printf("Longest Window = %d\n", result);
    return 0;
}
