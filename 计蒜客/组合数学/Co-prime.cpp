#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;
ll a[51],b[51];
void div(ll n){
    ll j=0;
    for(ll i=2; i*i<=n; i++)
        if(n%i==0){
            while(n%i==0)
                n/=i;
            a[++j]=i;
        }
    if(n>1) a[++j]=n;
    a[0]=j;
}
ll get_cnt(ll mid){
    ll g=0,sum=mid,t;
    b[++g]=1;
    for(ll i=1; i<=a[0]; i++){
        t=g;
        for(ll j=1; j<=g; j++){
            b[++t]=b[j]*a[i]*-1;
            sum+=mid/b[t];
        }
        g=t;
    }
    return sum;
}
int main(){
    int t,cas = 0;
    ll a,b;
    scanf("%d",&t);
    for(cas = 1;cas<=t;cas++){
        scanf("%lld%lld%lld",&a,&b,&n);
        div(n);
        printf("Case #%d: %lld\n",cas,get_cnt(b)-get_cnt(a-1));
    }
    return 0;
}
