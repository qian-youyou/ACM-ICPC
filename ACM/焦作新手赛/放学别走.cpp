#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 19260817;
const int maxn = 1007;
ll dp[maxn],n;
void init(){
    memset(dp,0,sizeof(dp));
    dp[0] = dp[1] = 1;
    for(int i = 2;i<maxn;i++)
        for(int j = 1;j<=i;j++){
            dp[i]=(dp[i]+dp[i-j]*dp[j-1])%mod;
        }
}
int main(){
    init();
    while(~scanf("%d",&n))
    printf("%lld\n",dp[n]);
    return 0;
}
