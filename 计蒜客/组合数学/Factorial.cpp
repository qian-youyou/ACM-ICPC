#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll my_pow(ll a, ll c){
    ll ans = 0;
    while(c/a){
        c/=a;
        ans+=c;
    }
    return ans;
}
ll solve(){
    ll num_2 = 0,num_5 = 0;
    num_2 = my_pow(2,n);
    num_5 = my_pow(5,n);
    return min(num_2,num_5);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<solve()<<endl;
    }
    return 0;
}
