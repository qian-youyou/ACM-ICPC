#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
char s[1007];
ll a[1007];
int re[26];
void init(){
    a[0] = 1;
    for(int i = 1;i<1007;i++){
        a[i] = a[i-1]*i%mod;
    }
}
ll cal(ll x){
    ll res=1;
    int k=mod-2;
    while(k){
        if(k&1)
            res=res*x%mod;
        x=x*x%mod;
        k>>=1;
    }
    return res;
}
ll solve(){
    memset(re,0,sizeof(re));
    int sum = 0,flag = 0,len = strlen(s);
    for(int i = 0;i<len;i++){
        re[s[i]-'a']++;
    }
    for(int i = 0;i<26;i++){
        if(re[i]%2){
            if(flag)
                return 0;
            else
                flag = 1;
        }
        re[i]/=2;
        sum+=re[i];
    }
    ll ans = a[sum];
    for(int i = 0;i<26;i++){
        if(re[i])
            ans = ans*cal(a[re[i]])%mod;
    }
    return ans;
}
int main(){
    init();
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        printf("%lld\n",solve());
    }
    return 0;
}
