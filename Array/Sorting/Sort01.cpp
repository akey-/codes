/* Program to sort an array containing 0 and 1's only
   Written By : Akey-
   Complexity : O(n)
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

void sort01(int a[],int i,int j)
{
    while(i<j)
    {
        if(a[i]>0)
        {
            a[i]=a[i]^a[j]^(a[j]=a[i]);
            j--;
        }
        else i++;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    sort01(a,0,n-1);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
}
