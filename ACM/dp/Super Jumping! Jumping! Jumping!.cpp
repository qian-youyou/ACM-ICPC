#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1007;
ll dp[maxn], a[maxn], ans;
int n;
int main(){
    while(~scanf("%d", &n) && n){
        memset(dp, 0, sizeof(dp));
        scanf("%lld", &a[0]);
        ans = dp[0] = a[0];
        for(int i = 1; i < n; i++){
            scanf("%lld", &a[i]);
            dp[i] = a[i];
            for(int j = 0; j < i; j++){
                if(a[i] > a[j]){
                    dp[i] = max(dp[i], dp[j] + a[i]);
                }
            }
            ans = max(ans, dp[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
