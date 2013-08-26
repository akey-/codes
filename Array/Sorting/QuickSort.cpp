/* Program to implement Quick sort on array
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 100000

void swap(int *a,int *b)
{
    *a=(*a)^(*b)^((*b)=(*a));
}

int partition(int a[],int start,int end)
{
    int pivot=a[end];
    int i=start-1;
    int j;

    for(j=start;j<=end-1;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }

    swap(&a[i+1],&a[end]);
    return (i+1);
}

void quick_sort(int a[],int left,int right)
{
    int index;
    if(left<right)
    {
        index=partition(a,left,right);
        quick_sort(a,left,index-1);
        quick_sort(a,index+1,right);
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

    quick_sort(a,0,n-1);

    printf("Array After Sorting :\n");
    for(int i=0;i<n;i++) printf("%d ",a[i]);printf("\n");

    return 0;
}
