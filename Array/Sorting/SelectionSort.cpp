/* Program to implement selection sort on array
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 100000

void selection_sort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        if(i!=min)
        {
            a[i]=a[i]^a[min]^(a[min]=a[i]);
        }
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

    selection_sort(a,n);

    printf("Array After Sorting :\n");
    for(int i=0;i<n;i++) printf("%d ",a[i]);printf("\n");

    return 0;
}
