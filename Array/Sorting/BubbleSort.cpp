/* Program to implement bubble sort on array
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 100000

void bubble_sort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j]>a[j+1])
            {
                a[j]=a[j]^a[j+1]^(a[j+1]=a[j]);
            }
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

    bubble_sort(a,n);

    printf("Array After Sorting :\n");
    for(int i=0;i<n;i++) printf("%d ",a[i]);printf("\n");

    return 0;
}
