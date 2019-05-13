#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 500500507;
const ll mi = 500500+1;
const ll maxn = 2e7;
ll a[4] = {2, 4, 8, 16};
ll prime[mi+100];
ll check[maxn], tot;
void init(){
    memset(check, 0, sizeof(check));
    prime[tot++] = 1;
    for (ll i = 2; i < maxn; ++i){
        if(!check[i]){
            prime[tot++] = i;
        }
        if(tot == mi){
            break;
        }
        for (ll j = 1; j < tot; ++j){
            if (i * prime[j] > maxn){
                break;
            }
            check[i*prime[j]] = 1;
            if (i % prime[j] == 0){
                break;
            }
        }
    }
}
ll Pow(ll a, ll b){
    ll ans = 1;
    for(ll i = 1; i <= b; i++){
        ans *= a;
        if(ans > prime[tot-1]){
            ans = prime[tot-1]+1;
            break;
        }
    }
    return ans;
}
int main(){
    init();
    priority_queue<ll>que;
    que.push(1);
    ll Size = 1;
    ll Top = 4;
    for(ll i = 1; i < mi; i++){
        if(Size >= mi){
            if(prime[i] >= que.top()){
                break;
            }
            else{
                que.pop();
                que.push(prime[i]);
                for(ll j = 0; j < Top; j++){
                    if(Pow(prime[i], a[j]) >= prime[tot-1]){
                        Top = j;
                        break;
                    }
                    if(Pow(prime[i], a[j]) >= que.top()){
                        Top = j;
                        break;
                    }
                    else{
                        que.pop();
                        que.push(Pow(prime[i], a[j]));
                    }
                }
            }
        }
        else{
            que.push(prime[i]);
            Size++;
            for(ll j = 0; j < Top; j++){
                if(Pow(prime[i], a[j]) >= prime[tot-1]){
                    Top = j;
                    break;
                }
                if(Size >= mi){
                    if(Pow(prime[i], a[j]) >= que.top()){
                        Top = j;
                        break;
                    }
                    else{
                        que.pop();
                        que.push(Pow(prime[i], a[j]));
                    }
                }
                else{
                    if(Pow(prime[i], a[j]) >= prime[tot-1]){
                        Top = j;
                        break;
                    }
                    que.push(Pow(prime[i], a[j]));
                    Size++;
                }
            }
        }
    }
    ll ans = 1;
    int SI = 0;
    while(!que.empty()){
        ans *= que.top();
        que.pop();
        ans%=mod;
        SI++;
    }
    cout<<ans<<endl;
    return 0;
}
