/* program to remove duplicate from a string
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
    char str[100];
    fgets(str,100,stdin);
    int len=strlen(str);
    sort(str,str+len);

    int j=0;
    for(int i=0;i<len;i++)
    {
        if(str[i]!=str[i+1])
            str[j++]=str[i];
    }

    str[j]='\0';
    puts(str);
}
