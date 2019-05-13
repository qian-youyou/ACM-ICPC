#include<bits/stdc++.h>
using namespace std;
const int maxn = 107;
int T, N, m;
int head[maxn], link[maxn];
bool vis[maxn];
int cnt;
struct EDGE{
    int next, u, to, w;
}edge[maxn];
void add(int u, int v, int w){
    edge[cnt].next = head[u];
    edge[cnt].u = u;
    edge[cnt].to = v;
    edge[cnt].w = w;
    head[u] = cnt++;
}
void init(){
    memset(edge, 0, sizeof(edge));
    memset(link, 0, sizeof(link));
    memset(head, -1, sizeof(head));
    cnt = 0;
}
bool find_edge(int x){
    for(int i = head[x]; i!= -1; i = edge[i].next){
        int v = edge[i].to;
        if(!vis[v]){
            vis[v] = true;
            if (!link[v] || find_edge(link[v])) {
				link[v] = x;
				return true;
			}
        }
    }
    return false;
}
int Magyar(int N){
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        memset(vis, false, sizeof(vis));
        if (find_edge(i)) {
            ans++;
        }
    }
    return ans;
}
int solve(){
    int ans = Magyar(N);
    return ans;
}
void read(){
    scanf("%d%d",&N, &m);
    while(m--){
        int x, y;
        scanf("%d%d",&x, &y);
        add(x, y, 1);
    }
}
int main(){
    scanf("%d", &T);
    while(T--){
        init();
        read();
        printf("%d\n", solve());
    }
    return 0;
}
