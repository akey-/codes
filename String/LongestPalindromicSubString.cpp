/* Program to find longest palindromic substring of a string
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int check(char str[],int i,int j)
{
    while(i<j)
    {
        if(str[i++]!=str[j--])
            return 0;
    }
    return 1;
}

int main()
{
    char str[10000];
    fgets(str,10000,stdin);
    int n=strlen(str);
    int maxl=0,si,ei;

        for(int j=0;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(check(str,j,k))
                {
                    int len=k-j;
                    if(len >maxl)
                    {
                        si=j,ei=k;
                        maxl=len;
                    }
                }
            }
        }
        for(int x=si;x<=ei;x++) printf("%c",str[x]);printf("\n");
    return 0;
}
