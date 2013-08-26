/* Program to implement insertion sort on array
   Written by : Akey-
*/

#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 100000

void insertion_sort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int k=a[i],j;
        for(j=i-1;j>=0 && a[j]>k;j--)
            a[j+1]=a[j];
        a[j+1]=k;
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

    insertion_sort(a,n);

    printf("Array After Sorting :\n");
    for(int i=0;i<n;i++) printf("%d ",a[i]);printf("\n");

    return 0;
}
