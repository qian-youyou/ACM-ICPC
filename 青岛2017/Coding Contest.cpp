#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxm = 1e5+7;
const int maxn = 1e4+7;
const int inf = 0x3f3f3f3f;
const double eps=1e-8;
int T, n, m, cnt, sx, ex;
int head[maxn], pre[maxn];
double dis[maxn];
bool vis[maxn];
struct EDGE{
    int next;
    int to;
    double w;
    int c;
}edge[maxm];
void init(){
    cnt = 0;
    //memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
}
void add(int u, int v, int c, double w){
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].c = c<=inf ? c : inf;
    edge[cnt].w = w;
    head[u] = cnt++;
    edge[cnt].next = head[v];
    edge[cnt].to = u;
    edge[cnt].c = 0;
    edge[cnt].w = -w;
    head[v] = cnt++;
}
bool SPFA(int sx, int ex){
    for(int i = 0; i <= n + 1; i++){
        dis[i] = inf;
        pre[i] = -1;
        vis[i] = false;
    }
    dis[sx] = 0;
    queue<int>que;
    que.push(sx);
    while(!que.empty()){
        int kk = que.front();
        que.pop();
        vis[kk] = false;
        for(int i = head[kk]; i != -1; i = edge[i].next){
            int v = edge[i].to;
            if(edge[i].c && dis[v]>dis[kk]+edge[i].w + eps){
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
double MCMF(int sx, int ex){
    int flow = 0;
    double cost = 0;
    while(SPFA(sx, ex)){
        int min_flow = inf;
        for(int i = pre[ex]; i != -1; i = pre[edge[i^1].to]){
            min_flow = min(min_flow, edge[i].c);
        }
        for(int i = pre[ex]; i != -1; i = pre[edge[i^1].to]){
            edge[i].c -= min_flow;
            edge[i^1].c += min_flow;
            cost += edge[i].w * min_flow;
        }
        flow += min_flow;
    }
    return cost;
}
void read(){
    int u, v, c;
    double w;
    int x, y;
    sx = 0, ex = n+1;
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &x, &y);
        if(x>y){
            add(0, i, x-y, 0);
        }
        else if(y>x){
            add(i, n+1, y-x, 0);
        }
    }
    for(int i = 0;i<m;i++){
        scanf("%d%d%d%lf",&u,&v,&c,&w);
        if(c){
            add(u, v, 1, 0);
        }
        --c;
        if(c){
            w = -log(1.0-w);
            add(u, v, c, w);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d", &T);
    while(T--){
        scanf("%d%d",&n,&m);
        init();
        read();
        double ans = MCMF(sx, ex);
        printf("%.2lf\n",1.0 - exp(-ans));
    }
    return 0;
}
