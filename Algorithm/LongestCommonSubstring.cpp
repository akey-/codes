/* Program to find the longest common substring of two string of same length
   Written By : Akey-
   Algorithm  : Dynamic Programming(DP)
   Complexity : O(n2)
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char str[200];
    char pat[200];
    scanf("%s%s",&str,&pat);

    int m=strlen(str);
    int n=strlen(pat);
    int dp[m+1][n+1];
    int res=0;
    int k;
    memset(dp,0,sizeof dp);
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 ||j==0)
                dp[i][j]=0;

            else if(str[j-1]==pat[i-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                res=max(res,dp[i][j]);
                if(dp[i][j]==res)
                    k=j;
            }
            else
                dp[i][j]=0;
        }
    }
    for(int i=k-res;i<k;i++)
        printf("%c",str[i]);
    printf("\n%d\n",res);
}


