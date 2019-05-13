#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[55] = {1,1};
ll fun(int n){
    if(dp[n])
        return dp[n];
    for(int i = 1;i<=n;i++)
        dp[n]+=fun(n-i);
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    cout<<fun(n)<<endl;
    return 0;
}
