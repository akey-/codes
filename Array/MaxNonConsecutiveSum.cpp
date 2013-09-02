/* Program to find Maximum sum such that no two elements are adjacent
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
using namespace std;

void withExtraSpace(int a[],int n)
{
    int sum[n+2];
    sum[0]=0;
    sum[1]=a[0];

    for(int i=2;i<n+1;i++)
        sum[i]=max(sum[i-1],sum[i-2]+a[i-1]);

    printf("%d\n",sum[n]);
}

void WithoutExtraSpace(int a[],int n)
{
    int incl=a[0];
    int excl=0;
    int expected=0;

    for(int i=1;i<n;i++)
    {
        //expected=max(incl,excl);incl=excl+a[i];excl=expected;//gfg sol
        expected=max(excl+a[i],incl);
        excl=incl;
        incl=expected;
    }

    printf("%d\n",max(incl,excl));
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",a+i);

    WithoutExtraSpace(a,n);
    return 0;
}

 
