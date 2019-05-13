#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxm = 1e6+7;
const int maxn = 1e5+7;
const int inf = 0x3f3f3f3f;
int n, cnt, sx, ex;
int Map[32][32];
int head[maxn], pre[maxn], dis[maxn];
bool vis[maxn];
struct EDGE{
    int u;
    int next;
    int to;
    int w;
    int c;
}edge[maxm];
void init(){
    cnt = 0;
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
}
void add_edge(int u, int v, int c, int w){
    edge[cnt].u = u;
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].c = c<=inf ? c : inf;
    edge[cnt].w = w;
    head[u] = cnt++;
}
void add(int u, int v, int c, int w){
    add_edge(u, v, c, w);
    add_edge(v, u, 0, -w);
}
bool SPFA(int sx, int ex){
    memset(pre, -1, sizeof(pre));
    memset(dis, -inf, sizeof(dis));
    memset(vis, false, sizeof(vis));
    dis[sx] = 0;
    queue<int>que;
    que.push(sx);
    while(!que.empty()){
        int kk = que.front();
        que.pop();
        vis[kk] = false;
        for(int i = head[kk]; i != -1; i = edge[i].next){
            int v = edge[i].to;
            if(edge[i].c && dis[v]<dis[kk]+edge[i].w){
                dis[v] = dis[kk] + edge[i].w;
                pre[v] = i;
                if(!vis[v]){
                    vis[v] = true;
                    que.push(v);
                }
            }
        }
    }
    return pre[ex] != -1;
}
int MCMF(int sx, int ex){
    int flow = 0, min_flow = inf, cost = 0;
    while(SPFA(sx, ex)){
        for(int i = pre[ex]; i != -1; i = pre[edge[i^1].to]){
            min_flow = min(min_flow, edge[i].c);
        }
        for(int i = pre[ex]; i != -1; i = pre[edge[i^1].to]){
            edge[i].c -= min_flow;
            edge[i^1].c += min_flow;
            cost += min_flow * edge[i].w;
        }
        flow += min_flow;
    }
    cost += Map[0][0] + Map[n-1][n-1];
    return cost;
}
void read(){
    int u, v, c, w;
    int nn = n*n;
    sx = 2*nn;
    ex = 2*nn+1;
    add(sx, nn, 2, 0);
    add(nn - 1, ex, 2, 0);
    for(int i = 0;i<n;i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &Map[i][j]);
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = 0; j < n; j++){
            add(i*n+j, nn+i*n+j, 1, Map[i][j]);
            if(i){
                add(nn + (i - 1)*n + j, i * n + j, 1, 0);
            }
            if(j){
                add(nn + i * n + j - 1, i * n + j, 1, 0);
            }
        }
    }
}
int main(){
    while(~scanf("%d",&n)){
        init();
        read();
        printf("%d\n", MCMF(sx, ex));
    }
    return 0;
}
