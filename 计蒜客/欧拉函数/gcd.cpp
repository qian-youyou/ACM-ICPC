#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e6+7;
const ll mod = 1e9+7;
ll size = 0;
ll pri[MAXN];
ll oula[MAXN];
ll sum[MAXN];
ll vis[MAXN];
void getprime(){
    memset(vis,0,sizeof(vis));
    vis[1]=1,oula[1]=0;
    for(int i=2;i<MAXN;i++){
        if(!vis[i])pri[++size]=i,oula[i]=i-1;
        for(int j=1;j<=size&&i*pri[j]<MAXN;j++){
            vis[i*pri[j]]=1;
            if(i%pri[j]==0){
                oula[i*pri[j]]=oula[i]*pri[j];
                break;
            }
            else oula[i*pri[j]]=oula[i]*(pri[j]-1);
        }
    }
}
void init(){
    sum[1] = 1;
    for(int i = 2;i<MAXN;i++){
        sum[i] = oula[i] + sum[i-1];
    }
}
ll quick_pow(ll a,ll n){
    ll res = 1;
    while(n){
        if(n&1)
            res = res * a % mod;
        a = a * a % mod;
        n>>=1;
    }
    return res;
}
ll fun(ll x,ll st, ll ed){
    if(x == 1)  return 0;
    ll temp1 = quick_pow(x, st) * ((1 - quick_pow(x, ed-st+1) + mod) % mod) % mod;
    ll temp2 = quick_pow(1-x+mod, mod-2);
    return (temp1 * temp2 % mod - (ed-st+1) + mod) % mod;
}
ll solve(ll x, ll n){
    ll ans = 0;
    ll i,j;
    for(i = 1;i<=n;i=j+1){
        j = n / (n / i);
        ans = (ans + (sum[n/i] * 2 - 1) % mod * (fun(x,i,j)) % mod) % mod;
    }
    return ans;
}
int main(){
    getprime();
    init();
    ll t,x,n;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&x,&n);
        printf("%lld\n",solve(x,n));
    }
    return 0;
}
