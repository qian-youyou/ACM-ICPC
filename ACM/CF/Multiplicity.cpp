#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e6+7;
const ll mod = 1e9+7;
ll ans = 0, top = 0, cur = 1;
ll re[maxn], yin[maxn];
void change(ll x){
    top = 0;
    ll nn = sqrt(x);
    for(ll i = nn; i > 0; i--){
        if(x%i == 0){
            if(i <= cur){
                yin[top++] = i;
            }
            if(x/i != i && x/i <= cur){
                yin[top++] = x/i;
            }
        }
    }
}
int main(){
    ll n, x;
    memset(re, 0, sizeof(re));
    re[0] = 1;
    scanf("%lld", &n);
    for(ll i = 1; i <= n; i++){
        scanf("%lld", &x);
        change(x);
        sort(yin, yin+top);
        for(int j = 0; j < top; j++){
            ans = (ans + re[yin[j] - 1])%mod;
        }
        for(int j = top-1; j >= 0; j--){
            if(re[yin[j] - 1] != 0){
                cur = max(cur, yin[j] + 1);
                re[yin[j]] += re[yin[j]-1];
                re[yin[j]] %= mod;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e6+7;
const ll mod = 1e9+7;
ll ans = 0, top = 0, cur = 1;
ll re[maxn], yin[maxn];
void fun(ll x){
    top = 0;
    for(ll i = 1; i <= cur; i++){
        if(x%i == 0){
            yin[top++] = i;
        }
    }
}
int main(){
    ll n, x;
    memset(re, 0, sizeof(re));
    re[0] = 1;
    scanf("%lld", &n);
    for(ll i = 1; i <= n; i++){
        scanf("%lld", &x);
        fun(x);
        for(int j = 0; j < top; j++){
            ans = (ans + re[yin[j] - 1])%mod;
        }
        for(int j = top - 1; j >= 0; j--){
            cur = max(cur, yin[j] + 1);
            re[yin[j]] += re[yin[j]-1];
            re[yin[j]] %= mod;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
*/
