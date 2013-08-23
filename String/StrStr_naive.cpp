/* Program to find whether a string is substring of another string or not
   Written By: Akey-
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int check(char str[],char pat[])
{
    int n=strlen(str);
    int m=strlen(pat);
    int i,j;
    for( i=0;i<n;i++)
    {
        if(str[i]==pat[0])
        {
            for( j=0;j<m && (i+j)<n;j++)
            {
                if(str[i+j]!=pat[j])
                    break;
            }
            if(j==m) return 1;
        }
    }
    return 0;
}

int main()
{
        char str[2000];
        gets(str);
        char pat[]="akey-";
        if(check(str,pat)) printf("YES\n");
        else printf("NO\n");
        return 0;
}
