#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 3007;
const int inf = 0x3f3f3f3f;
int road[maxn][maxn];
int dis[maxn];
bool vis[maxn];
int n, m, sx, ex;
void init(){
    memset(road, inf, sizeof(road));
}
int dijkstra(int sx, int ex){
    memset(vis, false, sizeof(vis));
    memset(dis, inf, sizeof(dis));
    dis[sx] = 0;
    for(int u = 1; u<=n; u++){
        int minD = inf, k = -1;
        for(int i = 1; i<= n; i++){
            if(!vis[i] && dis[i] < minD){
                k = i;
                minD = dis[i];
            }
        }
        //if(k == ex)
        //    return dis[ex];
        vis[k] = true;
        for(int i = 1; i<= n; i++){
            if(!vis[i] && dis[k] + road[k][i] < dis[i]){
                dis[i] = dis[k] + road[k][i];
            }
        }
    }
    return dis[ex];
}
void read(){
    int u, v, w;
    sx = 1, ex = n;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &u, &v, &w);
        road[u][v] = min(road[u][v], w);
        //road[v][u] = min(road[v][u], w);  //Ë«Ïò±ß
    }
}
void solve(){
    printf("%d\n", dijkstra(sx, ex));
}
int main(){
    while(~scanf("%d%d", &n, &m)){
        init();
        read();
        solve();
    }
    return 0;
}
