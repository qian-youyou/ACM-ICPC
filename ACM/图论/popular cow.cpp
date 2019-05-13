#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5 + 7;
const int inf = 0x3f3f3f3f;
int n, m;
int head[maxn], degree[maxn], cnt, top, dfs_num, col_num;
int dfn[maxn], low[maxn], Stack[maxn], color[maxn];
bool vis[maxn];
struct EDGE{
    int next, to, u;
}edge[maxn<<3];
void add(int u, int v){
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].u = u;
    head[u] = cnt++;
}
void Tarjan(int x){
    dfn[x] = ++dfs_num;
    low[x] = dfs_num;
    vis[x] = true;  //是否在栈中
    Stack[++top] = x;
    for(int i = head[x]; i != -1; i = edge[i].next){
        int v = edge[i].to;
        if(!dfn[v]){
            Tarjan(v);
            low[x] = min(low[x], low[v]);
        }
        else if(vis[v]){
            low[x] = min(low[x], dfn[v]);
        }
    }
    if(dfn[x] == low[x]){   //构成强连通分量
        vis[x] = false;
        color[x] = ++col_num;   //染色
        while(Stack[top] != x){ //清空
            color[Stack[top]] = col_num;
            vis [ Stack[ top-- ] ] = false ;
        }
        top--;
    }
}
void init_edge(){
    cnt = 0;
    memset(head, -1, sizeof(head));
}
void init(){
    top = dfs_num = col_num = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(color, 0, sizeof(color));
    memset(vis, false, sizeof(vis));
    memset(degree, 0, sizeof(degree));
}
void read(){
    int u, v;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &u, &v);
        add(u, v);
    }
}
void solve(){
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!color[i]){
            Tarjan(i);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int u = head[i]; u != -1; u = edge[u].next){
            if(color[i] != color[edge[u].to]){
                degree[color[i]]++;
            }
        }
    }
    int flag = 0, kk = -1;
    for(int i = 1; i <= col_num; i++){
        if(!degree[i]){
            flag++;
            kk = i;
        }
    }
    if(flag>1||flag==0){
        ans = 0;
    }
    else{
        for(int i = 1; i <= n; i++){
            if(color[i] == kk){
                ans++;
            }
        }
    }
    printf("%d\n", ans);
}
int main(){
    while(~scanf("%d%d", &n, &m)){
        init();
        init_edge();
        read();
        solve();
    }
    return 0;
}
