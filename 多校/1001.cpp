#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    scanf("%lld",&t);
    while(t--){
        ll n, tmp, cnt = 0,sum = 0;
        scanf("%lld",&n);
        priority_queue<ll,vector<ll>,greater<ll> >v,s;
        for(ll i = 0;i<n;i++){
            scanf("%lld",&tmp);
            if(!v.empty()){
                if(!s.empty()&&tmp>s.top()&&s.top()<=v.top()){
                    sum+=tmp-(s.top());
                    v.push(s.top());
                    s.pop();
                    s.push(tmp);
                }
                 else if(tmp>v.top()&&(s.empty()||s.top()>v.top())){
                    s.push(tmp);
                    sum+=tmp-(v.top());
                    v.pop();
                    cnt++;
                }
                else if(tmp<=v.top()){
                    v.push(tmp);
                }
            }
            else{
                if(!s.empty()&&tmp>s.top()){
                    v.push(s.top());
                    sum+=tmp-s.top();
                    s.pop();
                    s.push(tmp);
                }
                else
                    v.push(tmp);
            }
        }
        printf("%lld %lld\n",sum,2*cnt);
    }
    return 0;
}
