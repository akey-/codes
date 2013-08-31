/* Program to find the no of set bit in binary representation of an integer
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int a;
    scanf("%d",&a);
    int cnt=0;
    while(a)
    {
        if(a&1) cnt++;
        a>>=1;
    }
    cout<<cnt;
}
