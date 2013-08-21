/* Program To find the maximum sum subarray of an array 
   Algorithm  : Kaden's algorithm for finding maximum sum subarray
   Written By : Akey
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",a+i);

    int currSum=0;
    int maxSum=0;

    int start,end;

    for(int i=0;i<n;i++)
    {
        if(currSum<=0)
        {
            currSum=0;
            start=i;
        }
        currSum+=a[i];

        if(maxSum<currSum)
        {
             maxSum=currSum;
             end=i;
        }
    }

    printf("Sum :%d and between %d to %d indexes\n",maxSum,start,end);
    return 0;
}
