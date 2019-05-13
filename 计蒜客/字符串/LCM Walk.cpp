#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b){
    return a%b==0?b:gcd(b,a%b);
}
ll dfs(ll g,ll x,ll y){
    ll ans = 0;
    if(!(x%(g+y))){
        ans++;
        ll tmp = x*g/(g+y);
        ans+=dfs(gcd(max(tmp,y),min(tmp,y)),tmp,y);
    }
    if(!(y%(g+x))){
        ans++;
        ll tmp = y*g/(g+x);
        ans+=dfs(gcd(max(tmp,x),min(tmp,x)),x,tmp);
    }
    return ans;
}
int main(){
    ll t,x,y;
    scanf("%lld",&t);
    for(ll c = 1;c<=t;c++){
        scanf("%lld%lld",&x,&y);
        ll tmp = gcd(max(x,y),min(x,y));
        ll ans = dfs(tmp,x,y);
        printf("Case #%lld: %lld\n",c,++ans);
    }
    return 0;
}
