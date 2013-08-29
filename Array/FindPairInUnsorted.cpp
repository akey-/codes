/* Program to find the pair equal to given sum in an unsorted array
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int k;
    scanf("%d",&k);

    int hash[10000];
    memset(hash,0,sizeof hash);

    for(int i=0;i<n;i++)
        hash[a[i]]+=1;

    for(int i=0;i<n;i++)
    {
        if((hash[k-a[i]]>=2) ||(hash[k-a[i]]==1 && (k-a[i])!=a[i]))
        {
            printf("%d %d\n",a[i],k-a[i]);
            hash[a[i]]=0;
        }
    }
    return 0;
}
