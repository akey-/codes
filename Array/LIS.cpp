/* program to find Longest increasing sequence of an array 
   Written by : Akey-
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define FOR(n) for(int i=0;i<n;i++)
#define READ(a) scanf("%d",&a)
#define PRINT(a) printf("%d ",a)
using namespace std;

int longestIncreasingSubsequence(int arr[],int n)
{
    int *dp;
    dp=(int *)malloc(sizeof(int));

    FOR(n) dp[i]=1;

    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
            if(arr[i]>arr[j] && dp[i] < dp[j] + 1)
                dp[i]=dp[j]+1;

    int max=0;
    FOR(n) if(dp[i]>max) max=dp[i];
  
    free(dp);

    return max;
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    FOR(n) READ(arr[i]);

    int lis=longestIncreasingSubsequence(arr,n);
    printf("%d\n",lis);
    return 0;
}
