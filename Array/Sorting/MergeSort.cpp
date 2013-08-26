/* Program to implement merge sort on an array
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 100000

void _merge(int a[],int T[],int left,int mid,int right)
{
    int i=left;
    int j=mid;
    int k=left;

    while((i<=mid-1) && (j<=right))
    {
        if(a[i]<=a[j])
            T[k++]=a[i++];
        else
            T[k++]=a[j++];
    }

    while(i<=mid-1)
        T[k++]=a[i++];

    while(j<=right)
        T[k++]=a[j++];
}

void _copy(int a[],int T[],int low,int up)
{
    for(int i=low;i<=up;i++)
        a[i]=T[i];
}

void _merge_sort(int a[],int low,int up)
{
    int T[MAX];
    if(low<up)
    {
        int mid=(low+up)>>1;
        _merge_sort(a,low,mid);
        _merge_sort(a,mid+1,up);

        _merge(a,T,low,mid+1,up);
        _copy(a,T,low,up);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",a+i);

    printf("Array Before Sorting :\n");
    for(int i=0;i<n;i++) printf("%d ",a[i]);printf("\n");

    _merge_sort(a,0,n-1);

    printf("Array After Sorting :\n");
    for(int i=0;i<n;i++) printf("%d ",a[i]);printf("\n");

    return 0;
}
