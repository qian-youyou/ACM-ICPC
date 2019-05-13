#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e4+7;
const ll mod = 1e9+7;
ll dp[107][maxn];
ll n,w,h;
ll solve(){
    memset(dp,0,sizeof(dp));
    ll ans = 0;
    if(n > w * h){
        n = w*h;
    }
    for(int i = 0;i<=n;i++){
        dp[0][i] = 1;
    }
    for(int i = 1; i<=w; i++){
        for(int j = 0;j<=n; j++){
            for(int k = 0; k<=h&&k<=j; k++){
                dp[i][j]+=dp[i-1][j-k];
                dp[i][j]%=mod;
            }
        }
    }
    ans = (dp[w][n] - 1 - n/w + mod)%mod;
    return ans;
}
int main(){
    while(~scanf("%lld%lld%lld",&n,&w,&h)){
        printf("%lld\n",solve());
    }
    return 0;
}
