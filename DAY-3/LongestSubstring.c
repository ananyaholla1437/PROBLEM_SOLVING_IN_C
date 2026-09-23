#include <stdio.h>
#include <string.h>

int LongestWindow(char s1[], int n){
    int left = 0;
    int right = 0;
    int maxLen = 0;
    for(int right = 0; right < n; right++){
        for(int i = left; i < right; i++){
            if(s1[i] == s1[right]){
                left = i + 1;
                break;
            }
        }

        int len = right - left + 1;
        if(len > maxLen){
            maxLen = len;
        }
    }
    return maxLen;
}
int main(){
    char s1[] = "abcabcbb";
    int n = strlen(s1);
    int result = LongestWindow(s1, n);
    printf("Longest Window = %d\n", result);
    return 0;
}