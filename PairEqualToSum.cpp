/* Program to find all pair of an array which equals to given value
   Written By : Akey-
   Complexity :Time - o(n log n) 
               Space- o(1)
*/

#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

void calculate(int a[],int n,int k)
{
    int i=0,j=n-1;
    int sum=0;
    sort(a,a+n);

    while(i<j)
    {
        sum=a[i]+a[j];
        if(sum==k)
        {
            printf("%d %d\n",i,j);
            i++;j--;
        }
        else if(sum<k)
            i++;
        else if(sum>k)
            j--;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int k;
    scanf("%d",&k);
    calculate(a,n,k);
}
