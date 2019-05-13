#include<bits/stdc++.h>
using namespace std;
const int maxn = 2007;
const int inf = 0x3f3f3f3f;
int a[maxn], b[maxn], dp[maxn];
int k;
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        memset(dp, inf, sizeof(dp));
        dp[0] = 0;
        scanf("%d", &k);
        for(int i = 1; i <= k; i++){
            scanf("%d", &a[i]);
        }
        for(int j = 2; j <= k; j++){
            scanf("%d", &b[j]);
        }
        dp[1] = a[1];
        for(int i = 2; i <= k; i++){
            dp[i] = min(dp[i-2] + b[i], dp[i-1] + a[i]);
        }
        int ans = dp[k];
        int s = ans % 60;
        ans /= 60;
        int m = ans % 60;
        ans = ans / 60 + 8;
        ans %= 24;
        if(ans<12){
            printf("%02d:%02d:%02d am\n", ans, m, s);
        }
        else{
            printf("%02d:%02d:%02d pm\n", ans, m, s);
        }
    }
    return 0;
}
