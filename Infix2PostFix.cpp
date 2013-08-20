/* Program    : Infix To postfix
   Written by : Akey-
*/

#include<iostream>
#include<stack>
#include<vector>
#include<cctype>
using namespace std;

int priority(char ch)
{
    int pr;
    if(ch=='+')
        pr=1;
    else if(ch=='-')
        pr=2;
    else if(ch=='*')
        pr=3;
    else if(ch=='/')
        pr=4;
    else if(ch=='^')
        pr=5;
    return pr;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char str[500],post[500];
        stack<char>st;
        scanf("%s",str);
        int k=0;
        for(int i=0;str[i]!='\0';i++)
        {
            if(isalpha(str[i])) post[k++]=str[i];
            else if(str[i]=='(')  st.push(str[i]);
            else if(str[i]==')')
            {
                while(!st.empty() && st.top()!='(')
                    {
                        post[k++]=st.top();
                        st.pop();
                    }
                    st.pop();
            }
            else
            {
                while(!st.empty() && st.top()!='(' && ( priority(st.top()) > priority(str[i])))
                {
                    post[k++]=st.top();
                    st.pop();
                }
                st.push(str[i]);
            }
        }
        while(!st.empty())
        {
            post[k++]=st.top();
            st.pop();
        }
        post[k]='\0';
        printf("%s\n",post);
    }
    return 0;
}
