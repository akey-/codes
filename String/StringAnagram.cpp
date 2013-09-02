/* Program to check whether two strings are anagram or not
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

bool isAnagram(char* s1,char* s2)
{
    if(strlen(s1)!=strlen(s2)) return false;

    sort(s1,s1+strlen(s1));
    sort(s2,s2+strlen(s2));

    for(int i=0;i<strlen(s1);i++)
    {
        if(s1[i]!=s2[i]) return false;
    }
    return true;
}

bool isAnagram2(char *s1,char *s2)
{
    if(strlen(s1)!=strlen(s2)) return false;

    int hash[256]={0};

    for(int i=0;i<strlen(s1);i++)
        hash[s1[i]]++;

    for(int i=0;i<strlen(s2);i++)
        if(!hash[s2[i]])
            return false;

    return true;
}

int main()
{
    char s1[100],s2[100];
    cin>>s1;
    cin>>s2;

    if(isAnagram(s1,s2)) cout<<"Both String are anagram";
    else cout<<"String are not Anagram";
    return 0;
}
