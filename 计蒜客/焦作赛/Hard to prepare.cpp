#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
ll quick_pow(ll ans, ll res, ll n){
    while(n){
        if(n&1)
            ans = ans * res % mod;
        res = res * res % mod;
        n>>=1;
    }
    return ans;
}
ll solve(ll n, ll k){
    ll ans = 0;
    ll i = (n&1)+2;
    ll res = pow(k-1,i-2);
    for(;i<=n;i+=2){
        ans = (ans + res) % mod;
        res = res * (k - 1) % mod * (k - 1) % mod;
    }
    ans = ans * k % mod * (k - 2) % mod;
    ans = (ans + k) % mod;
    return ans;
}
int main(){
    ll t,n,k;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&k);
        k = quick_pow(1,2,k);
        printf("%lld\n",solve(n,k));
    }
    return 0;
}
