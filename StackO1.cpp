/* Program to push ,pop , and find minimum in o(1)
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

stack<int>s1;
stack<int>s2;

void push(int x)
{
    s1.push(x);
    if(s2.empty()||x<=s2.top())
        s2.push(x);
}
int main()
{
    int n;
    scanf("%d",&n);
    int k=n;
    while(n--)
    {
        int num;
        scanf("%d",&num);
        push(num);
        printf("MINIMUM : %d\n",s2.top());
    }

    return 0;
}
