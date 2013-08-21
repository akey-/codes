/* Program to find the the maximum length subarray with equal no of 0's and 1's in an array of 0 and 1's
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
map<int,int>Hash;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    for(int i=0;i<n;i++)
        if(a[i]==0) a[i]=-1;


    int sum=a[0];
    int tmp[n];
    tmp[0]=0;
    for(int i=0;i<n;i++)
    {
        tmp[i+1]=tmp[i]+a[i];
    }


    int start,end;
    int max=0;
    for(int i=0;i<=n;i++)
    {
        if(Hash.find(tmp[i])==Hash.end())Hash[tmp[i]]=i;
        else if(Hash.find(tmp[i])!=Hash.end())
        {
            int val=i-Hash[tmp[i]];
            if(val>max)
            {
                 max=val;
                 start=Hash[tmp[i]];
                 end=i-1;
            }
        }
    }


    for(int i=start;i<=end;i++)
        printf("%d ",a[i]>0?a[i]:0);

}
