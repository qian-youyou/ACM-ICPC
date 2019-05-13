#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxm = 1e5+7;
const int maxn = 1e4+7;
const int inf = 0x3f3f3f3f;
int n, m, cnt, sx, ex;
int head[maxn], pre[maxn], dis[maxn];
bool vis[maxn];
struct EDGE{
    int next;
    int to;
    int w;
    int c;
}edge[maxm];
void init(){
    sx = 0;
    ex = 1;
    cnt = 0;
    memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
}
void add_edge(int u, int v, int c, int w){
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
    memset(dis, inf, sizeof(dis));
    memset(vis, false, sizeof(vis));
    dis[sx] = 0;
    queue<int>que;
    que.push(sx);
    while(!que.empty()){
        int kk = que.front();
        que.pop();
        vis[kk] = false;
        for(int i = head[kk]; i != -1; i = edge[i].next){
            EDGE tmp = edge[i];
            if(tmp.c && dis[tmp.to]>dis[kk]+tmp.w){
                dis[tmp.to] = dis[kk] + tmp.w;
                pre[tmp.to] = i;
                if(!vis[tmp.to]){
                    vis[tmp.to] = true;
                    que.push(tmp.to);
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
    return cost;
}
void read(){
    int u, v, c, w;
    ex = n+1;
    for(int i = 0;i<m;i++){
        scanf("%d%d%d%d",&u,&v,&c,&w);
        add(u,v,c, w);
    }
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        if(n+m==0){
            break;
        }
        init();
        read();
        printf("%d\n",MCMF(sx, ex));
    }
    return 0;
}
