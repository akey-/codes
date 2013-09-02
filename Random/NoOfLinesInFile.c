/* Program to count no of lines in a file
   Written By : Akey-
*/

#include<stdio.h>
#include<string.h>

int main()
{
    FILE *fp1;
    fp1=fopen("DeleteNAfterMnode.c","r");
    if(fp1==NULL) {printf("File not found!!!"); return 0;}

    char ch;
    int cnt=0;
    do
    {
        ch=fgetc(fp1);
        if(ch=='\n')
            cnt++;
    }while(ch!=EOF);

    printf("No of lines in file is %d\n",cnt);
    fclose(fp1);

    return 0;
}
