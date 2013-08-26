/* Program to count inversion of an array
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 100000
int inversion;

int _merge(int a[],int T[],int left,int mid,int right)
{
    int i=left;
    int j=mid;
    int k=left;
    int inv=0;
    while((i<=mid-1) && (j<=right))
    {
        if(a[i]<=a[j])
            T[k++]=a[i++];
        else
        {
            T[k++]=a[j++];
            inv+=(mid-i);
        }

    }

    while(i<=mid-1)
        T[k++]=a[i++];

    while(j<=right)
        T[k++]=a[j++];
    return inv;
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

        inversion+=_merge(a,T,low,mid+1,up);
        _copy(a,T,low,up);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",a+i);
    _merge_sort(a,0,n-1);
    printf("Inversions :%d\n",inversion);

    return 0;
}
