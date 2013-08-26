/* Program to implement tail command of Linux
   Written By : Akey-
*/

#include<stdio.h>
#include<string.h>

void tail(FILE *fp,int n)
{
    FILE *fp1=fopen("C:/Coding/Examples/majorityElement.cpp","r");
    int c=1;
    int ch=fgetc(fp);

    while((c<n)&&(ch!=EOF))
    {
        if(ch=='\n') c++;
        ch=fgetc(fp);
    }

    if(c!=n)
    {
        ch=fgetc(fp1);
        while(ch!=EOF)
        {
            printf("%c",ch);
            ch=fgetc(fp1);
        }
        return;
    }

    int d=0;
    while(ch!=EOF)
    {
        if(ch=='\n')
            d++;
        ch=fgetc(fp);
    }
    ch=fgetc(fp1);
    while(d!=0)
    {
        if(ch=='\n')
            d--;
        ch=fgetc(fp1);
    }
    do
    {
        printf("%c",ch);
        ch=fgetc(fp1);
    }while(ch!=EOF);
}

int main()
{
    FILE *fp=fopen("C:/Coding/Examples/majorityElement.cpp","r");
    tail(fp,20);
    return 0;
}
