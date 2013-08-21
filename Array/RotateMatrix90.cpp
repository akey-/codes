/* Program to rotate matrix by 90 degree
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<list>
using namespace std;
#define max 4

void show(int matrix[max][max])
{
    int i,j;
    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }
}


void transpose(int matrix[max][max])
{
    int temp[max][max];
    int i,j;
    for( i=0;i<max;i++)
    {
        for( j=0;j<max;j++)
        {
            temp[i][j]=matrix[j][i];
        }
    }

    for(i=0;i<max;i++)
    {
        for(j=0;j<max;j++)
        {
            matrix[i][j]=temp[i][j];
        }
    }
}

void rotate_mat(int matrix[max][max])
{
    int i,j,t;
    for(i=0;i<max;i++)
    {
        for(j=0;j<max/2;j++)
        {
            t=matrix[i][j];
            matrix[i][j]=matrix[i][max-j-1];
            matrix[i][max-j-1]=t;
        }
    }

}
int main()
{
    int matrix[max][max];
    int i,j;
    for(i=0;i<max;i++)
    for(j=0;j<max;j++)
    scanf("%d",&matrix[i][j]);
    transpose(matrix);
    rotate_mat(matrix);
    show(matrix);
    return 0;
}
