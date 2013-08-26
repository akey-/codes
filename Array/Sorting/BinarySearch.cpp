/* Program to find an element in an array using binary search
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 100000

int binary_search(int a[],int left,int right,int k)
{
    while(left<right)
    {
        int mid=(left+right)>>1;
        if(a[mid]>k)
            right=mid;
        else if(a[mid]<k)
            left=mid+1;
        else if(a[mid]==k)
            return mid;
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",a+i);
    int k;
    scanf("%d",&k);

    int position=binary_search(a,0,n-1,k);
    if(position!=-1) printf("The number present at %d position\n",(position+1));
    else printf("The number did not present\n");
    return 0;
}
