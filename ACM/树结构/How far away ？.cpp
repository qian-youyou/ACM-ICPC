#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 4e4 + 7;
const int inf = 0x3f3f3f3f;
int n, m, head[maxn], fa[maxn], head_2[maxn], cnt, cnt_2, dis[maxn], sx;
bool vis[maxn];
struct EDGE{
    int next, to, u, w;
}edge[maxn];
struct QUERY{
    int next, to, u, lca, dis;
}query[maxn];
void add_edge(int u, int v, int w){
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].u = u;
    edge[cnt].w = w;
    head[u] = cnt++;
}
void add_query(int u, int v){
    query[cnt_2].next = head_2[u];
    query[cnt_2].to = v;
    query[cnt_2].u = u;
    head_2[u] = cnt_2++;
    query[cnt_2].next = head_2[v];
    query[cnt_2].to = u;
    query[cnt_2].u = v;
    head_2[v] = cnt_2++;
}
void init_edge(){
    memset(head, -1, sizeof(head));
    cnt = 0;
}
void init_query(){
    memset(head_2, -1, sizeof(head_2));
    cnt_2 = 0;
}
int root(int x){
    return x = x == fa[x] ? x : root(fa[x]);
}
void tarjan(int x) {
    fa[x] = x;
    for (int i = head[x]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        dis[v] = dis[x] + edge[i].w;
        tarjan(v);
        fa[root(v)] = x;
    }
    vis[x] = true;
    for (int i = head_2[x]; i != -1; i = query[i].next) {
        int v = query[i].to;
        if (vis[v]) {
            query[i].lca = query[i^1].lca = root(v);
            query[i].dis = query[i^1].dis = dis[v] + dis[x] - 2*dis[query[i].lca];
        }
    }
}
void read(){
    int u, v, w;
    scanf("%d%d", &n, &m);
    memset(vis, false, sizeof(vis));
    for(int i = 1; i < n; i++){
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
        vis[v] = true;
    }
    for(int i = 1; i<=n; i++){
        if(!vis[i]){
            sx = i;
            break;
        }
    }
    memset(vis, false, sizeof(vis));
    for(int i = 0; i<m; i++){
        scanf("%d%d", &u, &v);
        add_query(u, v);
    }
}
void solve(){
    memset(dis, 0, sizeof(dis));
    tarjan(sx);
    for(int i = 0; i < cnt_2; i+=2){
        printf("%d\n", query[i].dis);
    }
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        init_edge();
        init_query();
        read();
        solve();
    }
    return 0;
}
