/* Program to find the maximum sum subarray in 2-d array
   Algorithm  : Kadane's Algorithm
   Complexity : O(n^3)
*/

#include<iostream>
#include<cstdio>
using namespace std;

void kadane(int arr[],int n,int &x1,int &x2,int &max)
{
    int curr=0;
    max=0;
    x1=x2=0;
    int beg=0;

    for(int i=0;i<n;i++)
    {
        curr+=arr[i];
        if(curr>max)
        {
            max=curr;
            x2=i;
            x1=beg;
        }
        if(curr<0)
        {
            curr=0;
            beg=i+1;
        }
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int KADEN2D[n][m];
    int TMP[m+5];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&KADEN2D[i][j]);

    int curr,maxSum,fx1,fx2,fy1,fy2,x2,x1;
    fx1=fx2=fy1=fy2=maxSum=curr=-1;

    for(int i=0;i<n;i++)
    {
        memset(TMP,0,sizeof (TMP));
        for(int j=i;j<n;j++)
        {
            for(int k=0;k<m;k++)
                TMP[k]+=KADEN2D[j][k];
            kadane(TMP,m,x1,x2,curr);
            if(curr>maxSum)
            {
                fy1=x1;
                fy2=x2;
                fx1=i;
                fx2=j;
                maxSum=curr;
            }
        }
    }

    cout << "max Sum = " << maxSum << " from (" << fx1 << "," << fy1 << ") to ("  << fx2 << "," << fy2 << ")" << endl;
}
