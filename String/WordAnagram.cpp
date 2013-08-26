/* Program to check whether two string are anagram with respect to words in the strings
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cstring>
#include<vector>
#include <sstream>
using namespace std;

int main()
{
    char str1[100],str2[100];
    gets(str1);
    gets(str2);

    map<string,int>fre;
    map<string,int>:: iterator i;
    vector<string>tokens;
    vector<string>::iterator it;

    string buf;
    stringstream ss(str1);

    while(ss>>buf)
    {
        tokens.push_back(buf);
    }

    for(it=tokens.begin();it!=tokens.end();it++)
    {
        fre[*it]+=1;
    }


    char *token=strtok(str2," ");
    while(token!=NULL)
    {
        if(fre.find(token)==fre.end())
        {
            printf("Not Anagram\n");
            return 0;
        }
        else
            fre[token]--;

        token=strtok(NULL," ");
    }

    for(i=fre.begin();i!=fre.end();i++)
    {
        if(i->second!=0)
        {
            cout<<"Not Anagram"<<endl;
            return 0;
        }
    }

    cout<<"Anagram\n";
    return 0;
}
