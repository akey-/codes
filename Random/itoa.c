/* Program to convert an integer to a string
   Written By : Akey-
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int num;
	scanf("%d",&num);
	char number[100];
	int flag=false;

	if(num<0)
	{
		flag=true;
		num=-num;
	}

	int i=0;
	while(num)
	{
		number[i++]=num%10 + '0';
		num/=10;
	}
	if(flag)
		number[i++]='-';
	number[i]='\0';
	strrev(number);
	
	puts(number);
	return 0;
}
