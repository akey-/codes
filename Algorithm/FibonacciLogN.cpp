/* Program to find nth Fibonacci number in O(log n)
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
#define mod 1000000007

void multiply(ll F[2][2],ll M[2][2])
{
    ll w=((F[0][0]*M[0][0])%mod + (F[0][1]*M[1][0])%mod)%mod;
    ll x=((F[0][0]*M[0][1])%mod + (F[0][1]*M[1][1])%mod)%mod;
    ll y=((F[1][0]*M[0][0])%mod + (F[1][1]*M[1][0])%mod)%mod;
    ll z=((F[1][0]*M[0][1])%mod + (F[1][1]*M[1][1])%mod)%mod;
    F[0][0]=w;
    F[0][1]=x;
    F[1][0]=y;
    F[1][1]=z;
}
void power(ll n,ll F[2][2])
{
    if(n==0 || n==1)
        return;
    ll M[2][2]={{1,1},{1,0}};
    power(n/2,F);
    multiply(F,F);
    if(n%2)
        multiply(F,M);
}

ll fibonacci(ll n,ll F[][2])
{
    if(n==0)
        return 0;
    else if(n==1 || n==2)
        return 1;
    else
        power(n,F);

    return F[1][0];
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        ll F[2][2]={{1,1},{1,0}};
        ll ans=fibonacci(n,F);
        printf("%d\n",ans);
    }
    return 0;
}
