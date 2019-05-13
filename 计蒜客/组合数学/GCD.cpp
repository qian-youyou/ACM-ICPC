#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
typedef long long ll;
ll oula[maxn];
int a,b,c,d,k;
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
    ll r=0, t;
    for(int i=index; i<fac[m].cnt; ++i)
    {
        t=b/fac[m].prime[i];//b范围内有多少个数和m的因数为prime[i]
        r+=t-inc(i+1,t,m);//减去这些数就是b范围内和m互质的数的个数。
    }
    return r;
}
ll solve()
{
    b/=k;
    d/=k;
    if(b>d)
        swap(b,d);
    ll ans = 0;
    for(int i = 1; i <= b; ++i)
        ans+=oula[i];
    for(int i=b+1; i<=d; ++i)
        ans+=b-inc(0,b,i);
    return ans;
}
int main()
{
    getLa(maxn);
    int t;
    scanf("%d",&t);
    for(int cas = 1; cas<=t; ++cas){
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        if(k==0){
            printf("Case %d: 0\n",cas);
            continue;
        }
        printf("Case %d: %lld\n",cas,solve());
    }
    return 0;
}
