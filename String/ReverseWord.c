/* Program to reverse words in a string
   Written By : Akey-
*/

#include<stdio.h>
#include<string.h>

void reverse(char *s,int i,int j)
{
    while(i<j)
    {
        s[i]=s[i]^s[j]^(s[j]=s[i]);
        i++;
        j--;
    }
    return s;
}

int main()
{
    char str[100],ch[100];
    gets(str);
    void reverse(char *s,int i,int j);
    strrev(str);
    int i,j=0;
    for(i=0;i<strlen(str)+1;i++)
    {
        if(str[i]==' '||str[i]=='\t'||str[i]=='\0')
        {
            reverse(str,j,i-1);
            j=i+1;
        }
    }
    printf("%s",(str));
    return 0;

}
