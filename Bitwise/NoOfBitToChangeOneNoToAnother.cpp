/* Program to count the no of bits flips required to change one number to another
   Written by : Akey-
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int count = 0;
    a=a^b;

    while(a)
    {
        a&=(a-1);
        count ++;
    }
    printf("%d\n",count);
}
