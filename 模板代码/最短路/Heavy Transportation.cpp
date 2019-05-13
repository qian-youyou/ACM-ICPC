#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 1007;
const int maxm = 2e6+7;
const int inf = 0x3f3f3f3f;
struct NODE{
    int x, y;
}node[maxn];
struct EDGE{
    int next, to;
    int w;
}edge[maxm];
int head[maxn], cnt;
int dis[maxn];
bool vis[maxn];
int m, n, sx, ex;
void add(int u, int v, int w){
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    head[u] = cnt++;
}
void init(){
    cnt = 0;
    memset(head, -1, sizeof(head));
}
int dijkstra(int sx, int ex){
    memset(vis, false, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    for(int i = head[sx]; i != -1; i = edge[i].next){
        dis[edge[i].to] = edge[i].w;
    }
    dis[sx] = 0;
    for(int cas = 1; cas<=n; cas++){
        int minD = -1;
        int kk = -1;
        for(int i = 1; i<= n; i++){
            if(!vis[i] && dis[i] > minD){
                kk = i;
                minD = dis[i];
            }
        }
        if(kk == -1)
            break;
        vis[kk] = true;
        for(int i = head[kk]; i != -1; i = edge[i].next){
            int v = edge[i].to;
            if(!vis[v] && min(dis[kk], edge[i].w) > dis[v]){
                dis[v] = min(dis[kk], edge[i].w);
            }
        }
    }
    return dis[ex];
}
void read(){
    int u, v, w;
    sx = 1, ex = n;
    for(int i = 1; i <= m; i++){
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);  //Ë«Ïò±ß
    }
}
int main(){
    int cas = 0, T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        init();
        read();
        printf("Scenario #%d:\n", ++cas);
        printf("%d\n\n", dijkstra(1, n));
    }
    return 0;
}
