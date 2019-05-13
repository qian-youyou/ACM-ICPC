#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 307;
const int maxm = 4e5+7;
const double inf = 1e20;
struct NODE{
    int x, y;
}node[maxn];
struct EDGE{
    int next, to;
    double w;
}edge[maxm];
int head[maxn], cnt;
double dis[maxn];
bool vis[maxn];
int n, sx, ex;
void add(int u, int v, double w){
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    head[u] = cnt++;
}
double point_dis(NODE a, NODE b){
    return sqrt((double)pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}
void init(){
    cnt = 0;
    memset(head, -1, sizeof(head));
}
double dijkstra(int sx, int ex){
    memset(vis, false, sizeof(vis));
    for(int i = 0; i <= n; i++){
        dis[i] = inf;
    }
    dis[sx] = 0;
    for(int cas = 1; cas<=n; cas++){
        double minD = inf;
        int kk = -1;
        for(int i = 1; i<= n; i++){
            if(!vis[i] && dis[i] < minD){
                kk = i;
                minD = dis[i];
            }
        }
        if(kk == -1)
            break;
        vis[kk] = true;
        for(int i = head[kk]; i != -1; i = edge[i].next){
            int v = edge[i].to;
            if(!vis[v] && max(dis[kk], edge[i].w) < dis[v]){
                dis[v] = max(dis[kk], edge[i].w);
            }
        }
    }
    return dis[ex];
}
void read(){
    int u, v, w;
    sx = 1, ex = 2;
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &node[i].x, &node[i].y);
        for(int j = 1; j < i; j++){
            double w = point_dis(node[i], node[j]);
            add(i, j, w);
            add(j, i, w);  //Ë«Ïò±ß
        }
    }
}
int main(){
    int cas = 0;
    while((~scanf("%d", &n))&&n){
        init();
        read();
        printf("Scenario #%d\n", ++cas);
        printf("Frog Distance = %.3f\n\n", dijkstra(1, 2));
    }
    return 0;
}
