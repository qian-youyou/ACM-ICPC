#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxm = 1e5+7;
const int maxn = 1007;
const int inf = 0x3f3f3f3f;
int n, m, sx, ex, cnt;
int head[maxm], pre[maxm], dis[maxn];
bool vis[maxn];
struct EDGE{
    int u, next, to, c;
}edge[maxm<<3];
void add_edge(int u, int v, int c){
    edge[cnt].u = u;
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].c = c<=inf ? c : inf;
    head[u] = cnt++;
}
void add(int u, int v, int c){
    add_edge(u, v, c);
    add_edge(v, u, 0);
}
void init(){
    //memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    cnt = 0;
}
void read(){
    for(int i = 0; i < m; i++){
        int u, v, w;
        scanf("%d%d%d",&u, &v, &w);
        add_edge(u, v, w);
        cnt++;
    }
    scanf("%d%d", &sx, &ex);
}
bool BFS(int sx, int ex){
    memset(pre, 0, sizeof(pre));
    queue<int>que;
    que.push(sx);
    pre[sx] = 1;
    while(!que.empty()){
        int kk = que.front();
        que.pop();
        for(int i = head[kk]; i != -1; i = edge[i].next){
                int v = edge[i].to;
            if(!pre[v]&&edge[i].c){
                pre[v] = pre[kk] + 1;
                que.push(v);
            }
        }
    }
    return pre[ex] != 0;
}
int DFS(int pos, int flow){
    if(pos == ex || flow == 0)
        return flow;
    int f = flow;
    for(int i = head[pos]; i != -1; i = edge[i].next){
        int tmp, v = edge[i].to;
        if(edge[i].c && pre[pos] + 1 == pre[v] && (tmp = DFS(v, min(edge[i].c, flow)))>0){
            edge[i].c -= tmp;
            edge[i^1].c += tmp;
            flow -= tmp;
            if(flow == 0){
                break;
            }
        }
    }
    return f - flow;
}
int Dinic(int sx, int ex){
    int flow = 0;
    while(BFS(sx, ex)){
        flow += DFS(sx, inf);
    }
    return flow;
}
void SPFA(int sx, int ex){
    memset(dis, inf, sizeof(dis));
    queue<int>que;
    que.push(sx);
    dis[sx] = 0;
    while(!que.empty()){
        int kk = que.front();
        que.pop();
        vis[kk] = false;
        for(int i = head[kk]; i!=-1; i = edge[i].next){
            int v = edge[i].to;
            if(!vis[kk]&&dis[kk]+edge[i].c<dis[v]){
                dis[v] = dis[kk]+edge[i].c;
                que.push(v);
                vis[v] = true;
            }
        }
    }
}
void check(){
    int tmp = cnt;
    init();
    for(int i = 0; i<tmp; i+=2){
        if(dis[edge[i].u]+edge[i].c==dis[edge[i].to]){
            add(edge[i].u, edge[i].to, 1);
        }
    }
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d",&n, &m);
        init();
        read();
        SPFA(sx, ex);
        check();
        printf("%d\n", Dinic(sx, ex));
    }
    return 0;
}
