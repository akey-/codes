/* Program to find next date for a given date 
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<map>
using namespace std;

string month[12]={"JANUARY","FEBUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};
int daytab[][12]={{31,28,31,30,31,30,31,31,30,31,30,31},
                   {31,29,31,30,31,30,31,31,30,31,30,31}};

int main()
{
    int date,year;
    char input[100];
    cin>>date>>input>>year;
    map<string,int>mymap;

    for(int i=0;i<12;i++)
    {
        mymap[month[i]]=i;
    }

    int mnth=mymap[input];

    int isleap=0;
    if((year%4==0) && (year%100!=0) || (year%400==0))
        isleap=1;

    int new_date=(date+1)%(daytab[isleap][mnth]+1);

    if(new_date<date)
    {
        int new_month=(mnth+1)%12;
        if(new_month<mnth)
            year++;
        else
            year=year;

        date=new_date+1;
        mnth=new_month;
        cout<<date<<" "<<month[mnth]<<" "<<year<<endl;
        return 0;
    }

   cout<<new_date<<" "<<month[mnth]<<" "<<year<<endl;


}
