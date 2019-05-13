#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+7;
const int inf = 0x3f3f3f3f;
int R[maxn], L[maxn];
bool check(int n){
    for(int i = 0; i < n; i++){
        if(L[i]){
            return false;
        }
    }
    return true;
}
bool solve(int n){
    if(n < 3){
        return false;
    }
    for(int i = n; i < n + 5; i++){
        R[i] = L[i] = inf;
    }
    for(int i = 0; i < n - 2; i++){
        if(!L[i]){
            continue;
        }
        R[i] -= L[i];
        for(int j = i + 1; j < i + 3; j++){
            R[j] -= L[i];
            L[j] -= L[i];
            if(R[j] < 0){
                return false;
            }
            if(L[j] < 0){
                L[j] = 0;
            }
        }
        for(int j = i + 3; j < i + 5; j++){
            L[j] -= L[i];
            if(L[j] < 0){
                L[j] = 0;
            }
        }
        L[i] -= L[i];
    }
    R[n-2] -= L[n-1];
    R[n-1] -= L[n-1];
    L[n-2] -= L[n-1];
    L[n-1] -= L[n-1];
    if(R[n-2] < 0){
        return false;
    }
    if(L[n-2] < 0){
        L[n-2] = 0;
    }
    else if(L[n-2] > 0){
        if(R[n-3]>=L[n-2]&&R[n-1]>=L[n-2]){
            L[n-2] = 0;
        }
        else if(n > 3 && R[n-3]>=L[n-2]&&R[n-4]>=L[n-2]){
            L[n-2] = 0;
        }
    }
    return true;
}
int main(){
    int t, n;
    scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &L[i]);
            R[i] = L[i];
        }
        if(!solve(n)){
            printf("Case #%d: No\n", cas);
        }
        else if(check(n)){
            printf("Case #%d: Yes\n", cas);
        }
        else{
            printf("Case #%d: No\n", cas);
        }
    }
    return 0;
}
