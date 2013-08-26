/* Program to rotate an array by k position
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 100000

void _rotate(int a[],int b,int e)
{
    while(b<e)
    {
        a[b]=a[b]^a[e]^(a[e]=a[b]);
        b++;e--;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",a+i);
    int k;
    scanf("%d",&k);


    printf("Array Before Rotation :\n");
    for(int i=0;i<n;i++) printf("%d ",a[i]);printf("\n");

    _rotate(a,0,k-1);
    _rotate(a,k,n-1);
    _rotate(a,0,n-1);

    printf("Array After rotation :\n");
    for(int i=0;i<n;i++) printf("%d ",a[i]);printf("\n");
    return 0;
}
