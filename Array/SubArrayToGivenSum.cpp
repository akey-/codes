/* Program to find subarray equal to given sum
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",a+i);
    int sum,f=0;
    scanf("%d",&sum);

    int currSum=0,left=0,right;
    for(int i=0;i<n;i++)
    {
        currSum+=a[i];

        if(currSum>sum)
        {
            while(currSum>sum)
                currSum-=a[left++];
        }

        if(currSum==sum)
        {
            right=i;f=1;
            break;
        }
    }

    if(f) for(int i=left;i<=right;i++) printf("%d ",a[i]);
    else printf("No SubArray with given Sum\n");

    return 0;
}
