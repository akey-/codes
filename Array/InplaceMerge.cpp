/* Program to merge two sorted array inplace
   Written By : Akey-
*/

#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

void swap(int *a,int *b)
{
    (*a)=(*a)^(*b)^((*b)=(*a));
}

int main()
{
    int n,m;
    scanf("%d",&n);
    int a1[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a1[i]);
    scanf("%d",&m);
    int a2[m];
    for(int i=0;i<m;i++)
        scanf("%d",&a2[i]);

    for(int i=0;i<n;i++)
    {
        if(a1[i]>a2[0])
            swap(&a1[i],&a2[0]);
        for(int j=0;j<m-1;j++)
        {
            if(a2[j]>a2[j+1])
                swap(&a2[j],&a2[j+1]);
        }
    }

    for(int i=0;i<n;i++) printf("%d ",a1[i]);printf("\n");
    for(int i=0;i<m;i++) printf("%d ",a2[i]);
}
