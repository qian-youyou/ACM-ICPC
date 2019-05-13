#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn = 2e6;
ll prime[maxn];
void init(){
    for(ll i = 2; i < maxn; i++){
        prime[i] = i * i * i - (i-1)*(i-1)*(i-1);
    }
}
bool halfserch(ll x){
    int mind, L = 2, R = maxn - 1;
    while(L <= R){
        mind = (L + R)/2;
        if(prime[mind] == x){
            break;
        }
        else if(prime[mind] > x){
            R = mind - 1;
        }
        else if(prime[mind] < x){
            L = mind + 1;
        }
    }
    if(prime[mind] == x){
        return true;
    }
    return false;
}
int main(){
    int T;
    init();
    scanf("%d", &T);
    ll tmp;
    while(T--){
        scanf("%lld", &tmp);
        if(halfserch(tmp)){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
