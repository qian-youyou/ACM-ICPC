#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll c[10005][105],stone[105],dp[105][10005];
ll sum,n;
void init(){
    memset(c,0,sizeof(c));
    c[0][0] = 1;
    for(int i = 1;i<10005;i++){
        c[i][0] = 1;
        for(int j = 1;j<=i&&j<105;j++)
            c[i][j] = (c[i-1][j-1]+c[i-1][j])%mod;
    }
}
void read(){
    sum = 0;
    stone[0] = 0;
    for(int i = 1;i<=n;i++){
        scanf("%lld",&stone[i]);
        sum = (sum+stone[i])%mod;
    }
}
ll solve(){
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=sum;j++){
            dp[i][j] = dp[i-1][j];
            for(int k = 1;j-k>=0&&k<=stone[i];k++){
                dp[i][j] = (dp[i][j]+dp[i-1][j-k]*c[j][k]%mod)%mod;
            }
        }
    }
    ll ans = 0;
    for(int i = 1;i<=sum;i++)
        ans=(ans+dp[n][i])%mod;
    return ans;
}
int main(){
    init();
    int cas = 0;
    while(scanf("%lld",&n)!=EOF){
        read();
        printf("Case %d: %lld\n",++cas,solve());
    }
    return 0;
}
