/*
    一个人上班在售票机那里卖电影票，
    他可以一次取出一张电影票来卖给别人，
    也可以一次取出两张来卖给俩人，
    问这个人最早几点下班（即所有买票人都买完票了）。
    给了你k个人取票所用时间，
    k-1组两两组合后取票所用时间。
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
int dp[12][maxn];
int n;
int main(){
    while(~scanf("%d", &n)&&n){
        memset(dp, 0, sizeof(dp));
        int T, X, Mt = 0;
        for(int i = 0; i < n; ++i){
            scanf("%d%d", &X, &T);
            ++dp[X][T];
            Mt = max(T, Mt);
        }
        dp[0][0] = dp[1][0] = dp[2][0] = dp[3][0] = dp[7][0] = dp[8][0] = dp[9][0] = dp[10][0] = dp[4][0] = dp[6][0] = 0;
        dp[0][1] = dp[1][1] = dp[2][1] = dp[3][1] = dp[7][1] = dp[8][1] = dp[9][1] = dp[10][1] = 0;
        dp[0][2] = dp[1][2] = dp[2][2] = dp[8][2] = dp[9][2] = dp[10][2] = 0;
        dp[0][3] = dp[1][3] = dp[9][3] = dp[10][3] = 0;
        dp[0][4] = dp[10][4] = 0;
        for(int i = 1; i <= Mt; i++){
            dp[0][i] += max(dp[0][i-1], dp[1][i-1]);
            dp[10][i] += max(dp[10][i-1], dp[9][i-1]);
            for(int j = 1; j < 10; j++){
                dp[j][i] += max(max(dp[j-1][i-1],dp[j+1][i-1]), dp[j][i-1]);
            }
        }
        int ans = 0;
        for(int i = 0; i <= 10; ++i){
            ans = max(ans, dp[i][Mt]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
