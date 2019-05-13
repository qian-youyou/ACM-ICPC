#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 11;
ll a[maxn],m,n,ans;
ll gcd(ll a, ll b){
    return b?gcd(b,a%b):a;
}
ll LCM(ll a,ll b){
    return a*b/gcd(a,b);
}
ll read(){
    for(int i = 0;i<m;i++){
        scanf("%lld",&a[i]);
        if(!a[i]){
            m--;
            i--;
        }
    }
}
void dfs(ll th, ll now, ll step){
    if(step>m)
        return;
    ll lcm = LCM(now,a[th]);
    if(step&1)
        ans+=(n-1)/lcm;
    else
        ans-=(n-1)/lcm;
    for(ll p=th+1;p<m;p++)
        dfs(p,lcm,step+1);
}
ll solve(){
    ans = 0;
    for(ll i = 0;i<m;i++)
        dfs(i,a[i],1);
    return ans;
}
int main(){
    while(~scanf("%lld%lld",&n,&m)){
        read();
        printf("%lld\n",solve());
    }
    return 0;
}
