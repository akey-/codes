/* Program to reverse the words of a string using stack
   Written By : Akey-
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	char str[1000],tmp[100];
	fgets(str,1000,stdin);

	stack<string>st;

	int i=0;
	for(int j=0;i<strlen(str)-1;j++)
	{
		if(str[j]==' ' || str[j]=='\t' || j==(strlen(str)-1))
		{
			int k=0;
			for(int l=i;l<j;l++)
			{
				tmp[k++]=str[l];
			}
			tmp[k]='\0';
			string token(tmp);
			st.push(token);
			i=j+1;
		}
	}

	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
	return 0;
}	
