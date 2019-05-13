#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1007;
const int maxm = 1e6+7;
const int inf = 0x3f3f3f3f;
struct EDGE{
    int next, to, w;
}edge[2][maxm];
int head[2][maxn], dis[2][maxn], cnt;
bool vis[maxn];
int n, m, sx, ex;
struct NODE{
    int u;
    int dis;
    NODE(){}
    NODE(int x, int y) : u(x), dis(y){}
    bool operator <(const NODE &a)const{
		return dis>a.dis;
	}
};
void add(int u, int v, int w){
    edge[0][cnt].next = head[0][u];
    edge[0][cnt].to = v;
    edge[0][cnt].w = w;
    head[0][u] = cnt;
    edge[1][cnt].next = head[1][v];
    edge[1][cnt].to = u;
    edge[1][cnt].w = w;
    head[1][v] = cnt;
    cnt++;
}
void init(){
    cnt = 0;
    memset(head, -1, sizeof(head));
}
void dijkstra(int sx, int flag){
    memset(vis, false, sizeof(vis));
    dis[flag][sx] = 0;
    priority_queue<NODE>que;
    que.push(NODE(sx, 0));
    while(!que.empty()){
        NODE tmp = que.top();
        que.pop();
        int kk = tmp.u;
        vis[kk] = true;
        for(int i = head[flag][kk]; i != -1; i = edge[flag][i].next){
            int v = edge[flag][i].to;
            if(!vis[v] && dis[flag][kk] + edge[flag][i].w < dis[flag][v]){
                dis[flag][v] = dis[flag][kk] + edge[flag][i].w;
                que.push(NODE(v, dis[flag][v]));
            }
        }
    }
}
void read(){
    int u, v, w;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        //add(v, u, w);  //Ë«Ïò±ß
    }
}
void solve(){
    memset(dis, inf, sizeof(dis));
    dijkstra(sx, 0);
    dijkstra(sx, 1);
    int maxD = -1;
    for(int i = 1; i<= n; i++){
        maxD = max(maxD, dis[0][i] + dis[1][i]);
    }
    printf("%d\n", maxD);
}
int main(){
    while(~scanf("%d%d%d", &n, &m, &sx)){
        init();
        read();
        solve();
    }
    return 0;
}
