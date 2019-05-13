#include<bits/stdc++.h>
using namespace std;
const int maxn = 3007;
int n, k, a[maxn], dp[2][300007] = {0};
int main(){
    cin>>n>>k;
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    for(int i = 0;i<n;i++){
        dp[i%2][0] = 0;
        for(int j = 1;j <= k;j++){
            dp[i%2][j] = max(dp[i%2][j-1],dp[abs(i-1)%2][j - a[i]] + a[i]);
        }
        if(dp[i%2][k] == k){
            cout<<"o hu~"<<endl;
            return 0;
        }
    }
    cout<<"wo yo wo yo~"<<endl;
    return 0;
}
