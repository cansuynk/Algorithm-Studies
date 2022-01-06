#include <stdio.h>
using namespace std;

//dynamic programming
//Function to find length of longest increasing subsequence.
int longestSubsequence(int n, int a[])
{   
    int lis[n];
    lis[0] = 1;

    /* Compute optimized LIS values in
        bottom up manner */
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[i] > a[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }
    
    int max = lis[0];
    for(int i = 1; i < n; i++){
        if(lis[i] > max){
            max = lis[i];
        }
    }
    return max;
}

int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of lis is %d\n", longestSubsequence(n, arr));
 
    return 0;
}
