#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
const int maxn = 2e7 + 7;
const int inf = 0x3f3f3f3f;
int n, head[maxn], lq[maxn], rq[maxn], cur, cnt, top;
bool vis[maxn];
struct EDGE{
    int next, to, u;
}edge[maxn];
void add_edge(int u, int v){
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].u = u;
    head[u] = cnt++;
}
void init_edge(){
    memset(head, -1, sizeof(head));
    cnt = 0;
    memset(lq, 0, sizeof(lq));
    memset(rq, 0, sizeof(rq));
    cur = 0;
}
void dfs(int x){
    stack<int> S;
    lq[x] = 0;
    top = 0;
    S.push(x);
    while (S.size()){
        x = S.top();
        if (lq[x]){
            rq[x] = ++top;
            S.pop();
            continue;
        }
        lq[x] = ++top;
        for (int i = head[x] ; i != -1 ; i = edge[i].next){
            int y = edge[i].to;
            lq[y] = 0;
            S.push(y);
        }
    }
}
void read(){
    int u, v;
    scanf("%d", &n);
    top = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &u);
        for(int j = 1; j<=u; j++){
            add_edge(i, ++top);
        }
    }
    memset(vis, false, sizeof(vis));
    dfs(0);
}
void solve(){
    int u, v;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d%d", &u, &v);
        if(lq[u]<lq[v]&&rq[u]>rq[v]){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
}
int main(){
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        init_edge();
        read();
        if(cas!=1){
            printf("\n");
        }
        printf("Case %d:\n", cas);
        solve();
    }
    return 0;
}
