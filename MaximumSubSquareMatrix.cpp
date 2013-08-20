/* Program    : Maximum Size sub-square Matrix with all 1's
   Written by : Akey-
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
int a[100][100];

int miny(int a,int b,int c)
{
    return min(min(a,b),c);
}

int min(int a, int b, int c)
{
  int m = a;
  if (m > b)
    m = b;
  if (m > c)
    m = c;
  return m;
}

void FindMaxSubSquare()
{
    int s[n][m];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 || j==0)
                s[i][j]=a[i][j];

            else
            {
                if(a[i][j]==1)
                    s[i][j]=miny(s[i][j-1],s[i-1][j],s[i-1][j-1]) + 1;
                else
                    s[i][j]=0;
            }
        }
    }

    int max=s[0][0],maxi=0,maxj=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]>max)
            {
                max=s[i][j];
                maxi=i;
                maxj=j;
            }
        }
    }

    for(int i=maxi;i>maxi-max;i--)
    {
        for(int j=maxj;j>maxj-max;j--)
        {
            printf("%d ",a[i][j]);
        }printf("\n");
    }
}


int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);

    FindMaxSubSquare();
}
