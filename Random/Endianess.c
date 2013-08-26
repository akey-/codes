/* Program to check whether machine is big-endianess or little endianess
   Written By : Akey-
*/

#include<stdio.h>
int main()
{
    int i=5;
    char *s=(char*)&i;
    if(*s) printf("Little\n");
    else printf("Big");
}
