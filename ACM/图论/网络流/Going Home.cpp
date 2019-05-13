#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxm = 1e5+7;
const int maxn = 1e4+7;
const int inf = 0x3f3f3f3f;
int n, m, cnt, sx, ex;
int head[maxn], pre[maxn], dis[maxn];
bool vis[maxn];
struct point{
    int x, y;
};
struct EDGE{
    int cur;
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
    edge[cnt].cur = u;
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
    char Map[107][107];
    point a[maxn], b[maxn];
    int cnt_a = 0, cnt_b = 0;
    for(int i = 0;i<n;i++){
        scanf("%s",Map[i]);
        for(int j = 0; j < m; j++){
            if(Map[i][j] == 'm'){
                a[++cnt_a] = (point){i,j};
            }
            else if(Map[i][j] == 'H'){
                b[++cnt_b] = (point){i,j};
            }
        }
    }
    ex = cnt_a+cnt_b+1;
    for(int i = 1;i<=cnt_a;i++){
        add(sx,i,1,0);
    }
    for(int i = 1;i<=cnt_b;i++){
        add(cnt_a+i,ex,1,0);
    }
    for(int i = 1; i<=cnt_a; i++){
        for(int j = 1; j<=cnt_b; j++){
            int dist = abs(a[i].x-b[j].x)+abs(a[i].y-b[j].y);
            add(i, cnt_a+j, 1, dist);
        }
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
