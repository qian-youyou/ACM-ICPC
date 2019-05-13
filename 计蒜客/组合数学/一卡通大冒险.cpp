#include<bits/stdc++.h>
using namespace std;
const int mod = 1000;
const int maxn = 2007;
int dp[maxn][maxn];
void init(){
    memset(dp,0,sizeof(dp));
    dp[1][1] = 1;
    for(int i = 2;i<maxn;i++){
        dp[i][1] = dp[i-1][i-1]%mod;
        for(int j = 2;j<=i;j++){
            dp[i][j] = (dp[i-1][j-1]+dp[i][j-1])%mod;
        }
    }
}
int main(){
    init();
    int n,tmp;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&tmp);
        printf("%d\n",dp[tmp][tmp]);
    }
    return 0;
}
