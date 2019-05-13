#include<bits/stdc++.h>
using namespace std;
const int maxn = 107;
int a[maxn],dp[maxn],n,m;
void read(){
    for(int i = 1;i<=n;i++){
        int tmp;
        scanf("%d%d",&tmp,&a[i]);
        a[i] -= tmp;
        m-=tmp;
    }
}
int solve(){
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i = 1;i<=n;i++){
        for(int j = m;j>=1;j--){
            for(int k = 1;k<=a[i];k++){
                if(k<=j)
                    dp[j]+=dp[j-k];
            }
        }
    }
    return dp[m];
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        read();
        printf("%d\n",solve());
    }
    return 0;
}
