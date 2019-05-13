#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c, p1, p2, q1, q2;
const ll maxn = 1e5+7;
ll gcd(ll a, ll b){
    return !b?a:gcd(b, a%b);
}
void solve(){
    ll x,y;
    ll g = gcd(a,b);
    if(c%g!=0){
        printf("Kuon\n");
        return;
    }
    a/=g;
    b/=g;
    c/=g;
    g = 1;
    ll ans = 1e18;
    for(ll i = -maxn;i<maxn;i++){
        y = c - a*i;
        if(y%b)
            continue;
        y/=b;
        ans = min(ans,p2*i*i+p1*i+q2*y*y+q1*y);
    }
    printf("%lld\n",ans);
}
int main(){
    while(~scanf("%lld%lld%lld",&a, &b, &c)){
        scanf("%lld%lld",&p1, &p2);
        scanf("%lld%lld",&q1, &q2);
        solve();
    }
    return 0;
}
