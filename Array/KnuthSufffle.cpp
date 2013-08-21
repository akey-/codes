/* Program to generate random list of number 1..n
   Written by : Akey-
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) a[i]=i+1;

    int len=n;
    while(len>0)
    {
        int i=rand()%len;
        a[i]=a[i]^a[len-1]^(a[len-1]=a[i]);
        len--;
    }

    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}
