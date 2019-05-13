#include<bits/stdc++.h>
using namespace std;
const int maxn = 507;
const int inf = 0x3f3f3f3f;
int N, E, F;
int dp[maxn*20];
int V[maxn], W[maxn];
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> E >> F;
        F -= E;
        cin >> N;
        memset(dp, inf, sizeof(dp));
        dp[0] = 0;
        for(int i = 0; i < N; i++){
            cin >> V[i] >> W[i];
            for(int j = W[i]; j < maxn*20; j++){
                dp[j] = min(dp[j-W[i]]+V[i], dp[j]);
            }
        }
        int ans = dp[F];
        if(ans != inf){
            cout << "The minimum amount of money in the piggy-bank is " << ans << ".\n";
        }
        else{
            cout << "This is impossible.\n";
        }
    }
    return 0;
}
