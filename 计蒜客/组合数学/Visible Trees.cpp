#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
typedef long long ll;
ll oula[maxn];
int m,n;
struct Number
{
    int cnt;
    int prime[20];
} fac[maxn];
void getLa( int n)
{
    memset(fac,0,sizeof(fac));
    for(int i = 0; i < n; ++i)
        oula[i] = i;
    for(int i = 2; i < n; ++i)
        if( oula[i] == i )
            for(int j = 1; j*i < n; ++j){
                oula[j*i] -= oula[j*i]/i;
                fac[j*i].prime[fac[j*i].cnt++]=i;
            }
}
ll inc(int index,int b,int m)
{
    ll r=0,t;
    for(int i=index; i<fac[m].cnt; ++i)
    {
        t=b/fac[m].prime[i];
        r+=t-inc(i+1,t,m);
    }
    return r;
}
ll solve()
{
    if(m>n)
        swap(m,n);
    ll ans = 0;
    for(int i = 1; i <= m; ++i)
        ans+=oula[i];
    ans=ans*2-1;
    for(int i=m+1; i<=n; ++i)
        ans+=m-inc(0,m,i);
    return ans;
}
int main()
{
    getLa(maxn);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&n);
        printf("%lld\n",solve());
    }
    return 0;
}
