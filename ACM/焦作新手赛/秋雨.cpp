#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll  f0, f1, b0, b1, c, n, M;
ll ksc(ll a,ll b, ll mod){
    return (a*b-(ll)((long double)a/mod*b)*mod+mod)%mod;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int cas = 1; cas<=t; cas++){
        scanf("%lld%lld%lld%lld%lld%lld%lld",&f0, &f1, &b0, &b1, &c, &n, &M);
        ll s = ksc(f0,f1,M);
        for(int i = 2; i <= n; i++){
            f0 = (ksc(f1,b0,M) + ksc(f0, b1,M) + c)%M;
            swap(f0, f1);
            s = ksc(s, f1, M);
        }
        printf("case #%d:\n%lld\n%lld\n",cas,f1,s);
    }
    return 0;
}
