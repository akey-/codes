/* Program to check whether paranthesis are valid or not within an expression
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

    bool isValid(char s[]) {
        stack<char>st;
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            st.push(s[i]);
            else if(s[i]==')')
            {
                if(!st.empty() && st.top()=='(')
                st.pop();
                else
                return false;
            }
            else if(s[i]==']')
            {
                if(!st.empty() && st.top()=='[')
                st.pop();
                else
                return false;
            }
            else if(!st.empty() && s[i]=='}')
            {
                if(st.top()=='{')
                st.pop();
                else
                return false;
            }
        }
        
        if(st.empty()) return true;
        else return false;
    }

    int main()
    {
        int n;
        scanf("%d",&n);
        while(n--)
        {
            char str[100];
            scanf("%s",str);
            if(isValid(str)) printf("Valid ...\n");
            else printf("Not Valid...\n");
        }
    }

