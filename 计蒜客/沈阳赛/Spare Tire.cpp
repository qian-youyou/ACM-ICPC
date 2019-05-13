#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;
ll maxn = 1e8+7;
ll m,n,ans;
ll gcd(ll x,ll y)
{
    ll t;
    while (y)
        t=x, x=y, y=t%y;
    return x;
}
int main()
{
    ans = 0;
    scanf("%lld%lld",&n,&m);
    for(ll i = 1; i<=n; i++)
    {
        if(gcd(i,m)==1)
            ans+=i*(i+1)%mod;
            ans%=mod;
    }
    printf("%lld\n",ans);
    return 0;
}
