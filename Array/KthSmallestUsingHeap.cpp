/* Program to find kth samllest element of an unsorted array 
   Written By : Akey -
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

vector<int>maxHeap;

void insert(int val)
{
    pop_heap(maxHeap.begin(),maxHeap.end());
    maxHeap.pop_back();
    maxHeap.push_back(val);
    push_heap(maxHeap.begin(),maxHeap.end());
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",a+i);
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        maxHeap.push_back(a[i]);
    }
    make_heap(maxHeap.begin(),maxHeap.end());

    for(int i=k;i<n;i++)
    {
        if(a[i]<maxHeap[0])
            insert(a[i]);
        else continue;
    }

    printf("%d\n",maxHeap[0]);
    return 0;
}
