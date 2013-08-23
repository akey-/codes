/* Program to convert lower case letter to upper case and vice-versa using single statement
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char str[100];
    fgets(str,100,stdin);

    for(int i=0;str[i]!='\0';i++)
    if(str[i]!=' ' )
        str[i]^=32;
    str[strlen(str)]='\0';

    printf("%s\n",str);
    return 0;
}
