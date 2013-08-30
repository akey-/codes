/* Program to find the median of infinite stream of integer
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

vector<int>minHeap;  //for storing value greater than median
vector<int>maxHeap;  //for storing value less than or equal to median

void insert(int val)
{
    if((minHeap.size() + maxHeap.size())% 2 ==0)
    {
        if(maxHeap.size()>0 && val<maxHeap[0])
        {
            maxHeap.push_back(val);
            push_heap(maxHeap.begin(),maxHeap.end());
            val=maxHeap[0];
            pop_heap(maxHeap.begin(),maxHeap.end());
            maxHeap.pop_back();
        }
        minHeap.push_back(val);
        push_heap(minHeap.begin(),minHeap.end(),greater<int>());
    }
    else
    {
        if(minHeap.size()>0 && val >minHeap[0])
        {
            minHeap.push_back(val);
            push_heap(minHeap.begin(),minHeap.end(),greater<int>());
            val=minHeap[0];
            pop_heap(minHeap.begin(),minHeap.end(),greater<int>());
            minHeap.pop_back();
        }
        maxHeap.push_back(val);
        push_heap(maxHeap.begin(),maxHeap.end());
    }
}

float median()
{
    int count=minHeap.size() + maxHeap.size();
    if(count==0)
        return -1;
    if(count%2==0)
        return (float)(minHeap[0]+maxHeap[0])/2;
    else
        return minHeap[0];
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t-->0)
    {
        int type;
        scanf("%d",&type);
        if(type==1)
        {
            int num;
            scanf("%d",&num);
            insert(num);
        }
        else if(type==2)
        {
            printf("%f\n",median());
        }
    }

    return 0;
}
