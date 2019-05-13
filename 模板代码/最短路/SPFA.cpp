#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3+7;
int n, m, sx, ex;
int head[maxn], dis[maxn], cnt;
bool vis[maxn];
struct EDGE{
    int next, to, w, u;
}edge[maxn<<3];
void init(){
    cnt = 0;
    memset(head, -1, sizeof(head));
}
void add(int u, int v, int w){
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].u = u;
    edge[cnt].w = w;
    head[u] = cnt++;
}
int SPFA(int sx, int ex){
    memset(vis, false, sizeof(vis));
    memset(dis, inf, sizeof(dis));
    queue<int>que;
    dis[sx] = 0;
    que.push(sx);
    while(!que.empty()){
        int kk = que.front();
        que.pop();
        vis[kk] = false;
        for(int i = head[kk]; i != -1; i = edge[i].next){
            int v = edge[i].to;
            if(dis[v] > dis[kk] + edge[i].w){
                dis[v] = dis[kk] + edge[i].w;
                if(!vis[v]){
                    vis[v] = true;
                    que.push(v);
                }
            }
        }
    }
    return dis[ex];
}
int main(){
    while(~scanf("%d%d", &n, &m)){
        init();
        sx = 1, ex = n;
        for(int i = 0; i < m; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
            //add(v, u, w);   //Ë«Ïò±ß
        }
        printf("%d\n", SPFA(sx, ex));
    }
}
