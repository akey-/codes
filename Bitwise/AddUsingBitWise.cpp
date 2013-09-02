/* Program to add two number using bitwise operator
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
using namespace std;

int add(int a,int b)
{
    int carry;

    while(b!=0)
    {
        carry=a&b;
        a=a^b;
        b=carry<<1;
    }
    return a;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<add(a,b);
}
