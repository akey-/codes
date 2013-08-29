/* Program to add two numbers represented by string
   Written by : Akey-
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char num1[100],num2[100],sum[200];
    fgets(num1,100,stdin);
    fgets(num2,100,stdin);

    int l=strlen(num1)-2,m=strlen(num2)-2,k=0;

    int carry=0;
    while(l>=0 && m>=0)
    {
        int s=num1[l]-'0'+ num2[m]-'0' + carry;
        if(s>=10)
        {
            s=s%10;
            carry=1;
        }
        else carry=0;
        sum[k++]=s +'0';
        l--;m--;
    }
    while(l>=0)
        sum[k++]=num1[l--];

    while(m>=0)
        sum[k++]=num2[m--];

    sum[k]='\0';
    int start=0;int end=k-1;
    while(start<end)
    {
        sum[start]=sum[start]^sum[end]^(sum[end]=sum[start]);
        start++;
        end--;
    }

    printf("%s",sum);
}
