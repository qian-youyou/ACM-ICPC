#include<bits/stdc++.h>
using namespace std;
const int maxn = 3007;
int dp[maxn][3],n;
int s[maxn];
int c[maxn];
int main(){
    cin>>n;
    int maxx=-1;
    memset(dp,-1,sizeof(dp));
    for(int i = 0;i<n;i++){
        cin>>s[i];
    }
    for(int i = 0;i<n;i++){
        cin>>c[i];
    }
    for(int i = 0;i<n;i++){
        dp[i][0]=c[i];
        for(int j = 0;j<i;j++){
            if(s[i]>s[j]){
                if(dp[j][0]!=-1){
                    dp[i][0]=min(dp[i][0],dp[j][0]);
                    if(dp[j][1]!=-1){
                        dp[i][1]=dp[i][1]==-1?min(dp[j][1],dp[j][0]+c[i]):min(min(dp[j][1],dp[j][0]+c[i]),dp[i][1]);
                        if(dp[j][2]!=-1){
                            dp[i][2]=dp[i][2]==-1?min(dp[j][2],dp[j][1]+c[i]):min(min(dp[j][2],dp[j][1]+c[i]),dp[i][2]);
                        }
                        else{
                            dp[i][2]=dp[i][2]==-1?dp[j][1]+c[i]:min(dp[j][1]+c[i],dp[i][2]);
                        }
                    }
                    else{
                        dp[i][1]=dp[i][1]==-1?dp[j][0]+c[i]:min(dp[j][0]+c[i],dp[i][1]);
                    }
                }
            }
            else if(s[i]==s[j]){
                if(c[i]>c[j]){
                    dp[i][0]=dp[j][0];
                    dp[i][1]=dp[j][1];
                    dp[i][2]=dp[j][2];
                }
            }
            if(dp[i][2]!=-1)
                if(maxx!=-1)
                    maxx=min(maxx,dp[i][2]);
                else
                    maxx=dp[i][2];
        }
    }
    cout<<maxx<<endl;
    return 0;
}
