/* Program to swap the two number without using extra variable
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
  int a,b;
  scanf("%d%d",&a,&b);
  
  printf("Value before swap : a=%d b=%d\n",a,b);
  
  #if 0
  a=a+b-(b=a);
  #endif
  
  #if 0
  a=a+b;
  b=a-b;
  a=a-b;
  #endif
  
  #if 0
  a=a^b^(b=a);
  #endif
  
  a=a^b;
  b=a^b;
  a=a^b;
  
  printf("Value after swap : a=%d b=%d",a,b);
}
