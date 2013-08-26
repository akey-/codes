/* Program to delete comment from a file
   Written By : Akey-
*/

#include<stdio.h>
#include<string.h>

int main()
{
    FILE *fp1,*fp2;
    fp1=fopen("Hackerrank_findPalin.cpp","r");
    fp2=fopen("out","w");
    if(fp1==NULL) {printf("File not found!!!"); return 0;}

    char ch;
    do
    {
        ch=fgetc(fp1);
        if(ch=='/')
        {
            char ch1=fgetc(fp1);
            if(ch1=='*')
            {
                int i=0;
                while(1)
                {
                    printf("%d ",i++);
                    ch=fgetc(fp1);
                    ch1=fgetc(fp1);
                    if(ch=='*' && ch1=='/') break;
                }
            }
            else if(ch1=='/')
            {
                while(ch1!='\n')
                    ch1=fgetc(fp1);
            }
        }

        else fputc(ch,fp2);
    }while(ch!=EOF);

    fclose(fp1);
    fclose(fp2);

    return 0;
}
