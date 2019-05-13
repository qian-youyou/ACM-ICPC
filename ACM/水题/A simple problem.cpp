#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
int T, n;
bool vis[maxn];
void solve(){
    memset(vis, false, sizeof(vis));
    vis[0] = true;
    if(n < 0){
        n = -n;
        putchar('-');
    }
    if(n == 1){
        puts("1\n");
        return;
    }
    else{
        putchar('0');
        putchar('.');
    }
    int cur = 1;
    while(!vis[cur]){
        vis[cur] = true;
        cur *= 10;
        putchar(cur/n+'0');
        cur %= n;
    }
    putchar('\n');
}
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        solve();
    }
    return 0;
}
