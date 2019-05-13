#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
const int maxn = 501;
const ll mod = 1000000007;
ll a[4], sum[4] = { 0 };
ll dp[maxn * 4][maxn * 4];
void init() {
	dp[0][0] = 0;
	for (int i = 1; i < 4 * maxn; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			dp[i][j] %= mod;
		}
		dp[i][i] = 1;
	}
}
int main() {
    int t;
    cin>>t;
    while(t--){
	init();
	ll ans = 1;
	for (int i = 0; i < 4; i++) {
		!i ? sum[i] = 0 : sum[i] = sum[i - 1];
		cin >> a[i];
		sum[i] += a[i];
		if (a[i] > sum[i] - a[i]) a[i] = sum[i] - a[i];
	}
	for (int i = 1; i < 4; i++) {
		ans *= dp[sum[i]][a[i]];
		ans %= mod;
	}
	cout << ans << endl;}
	return 0;
}
