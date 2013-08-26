/* Program to remove space from string
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char str[100];
    gets(str);
    int len=strlen(str);

    int p1=0,p2=0;

    for(int i=0;i<len;i++)
    {
        if(str[i]!=' ' && str[i]!='\t')
        {
            str[p1++]=str[i];
        }
    }
    str[p1]='\0';
    cout<<str;
}

// Below are the few more method to remove space from a string
#if 0
for(i=0;i< str.size();i++)
{
        if(str[i]!=' ')
        {
                str[j++]=str[i];
                count=0;
        }
        else if(str[i]==' '&&count==0)
        {
                str[j++]=str[i];
                count =1;
        }
}
#endif // 0

#if 0
void removeSpace(char *str) {
  char *p1 = str, *p2 = str;
  do
    while (*p2 == ' ')
      p2++;
  while (*p1++ = *p2++);
}
#endif // 0
