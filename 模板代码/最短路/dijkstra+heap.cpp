#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 3007;
const int inf = 0x3f3f3f3f;
struct EDGE{
    int next, to, w;
}edge[maxn<<4];
int head[maxn], dis[maxn], cnt;
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
    memset(dis, inf, sizeof(dis));
    dis[sx] = 0;
    priority_queue<NODE>que;
    que.push(NODE(sx, 0));
    while(!que.empty()){
        NODE tmp = que.top();
        que.pop();
        int kk = tmp.u;
        if(vis[kk]){
            continue;
        }
        vis[kk] = true;
        for(int i = head[kk]; i != -1; i = edge[i].next){
            int v = edge[i].to;
            if(!vis[v] && dis[kk] + edge[i].w < dis[v]){
                dis[v] = dis[kk] + edge[i].w;
                que.push(NODE(v, dis[v]));
            }
        }
    }
    return dis[ex];
}
void read(){
    scanf("%d%d", &n, &m);
    int u, v, w;
    sx = 1, ex = n;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);  //Ë«Ïò±ß
    }
}
void solve(){
    printf("%d\n", dijkstra(sx, ex));
}
int main(){
    int T;
    while(T--){
        init();
        read();
        solve();
    }
    return 0;
}
