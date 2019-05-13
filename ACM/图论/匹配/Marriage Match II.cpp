#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 107;
int T, n, m, f;
int head[maxn], link[maxn], fa[maxn] ;
bool vis[maxn], g[maxn][maxn];
int cnt;
struct EDGE{
    int next, u, to, w;
}edge[maxn*1000];
void add(int u, int v, int w){
    edge[cnt].next = head[u];
    edge[cnt].u = u;
    edge[cnt].to = v;
    edge[cnt].w = w;
    head[u] = cnt++;
}
void init_union(int N){
    for(int i = 0; i <= N; i++){
        fa[i] = i;
    }
}
int root(int x){
    return x == fa[x] ? x : x = root(fa[x]);
}
void Union(int px, int py){
    px = root(px), py = root(py);
    if(px != py){
        fa[py] = px;
    }
}
void init(){
    memset(edge, 0, sizeof(edge));
    memset(link, 0, sizeof(link));
    memset(head, -1, sizeof(head));
    memset(g, false, sizeof(g));
    cnt = 0;
}
void read(){
    scanf("%d%d%d", &n, &m, &f);
    int a, b;
    init_union(n);
    for(int i = 1; i<=m; i++){
        scanf("%d%d", &a, &b);
        add(a, b, 1);
        g[a][b] = true;
    }
    for(int i = 1; i<=f; i++){
        scanf("%d%d", &a, &b);
        Union(a, b);
    }
    for(int i = 1; i <= n; i++){
        int x = root(i);
        for (int j = 1; j <= n; j++){
            if (j != i && root(j) == x){
                for (int k = head[j]; k != -1; k = edge[k].next){
                    int v = edge[k].to;
                    if (!g[i][v]){
                        add(i, v, 1);
                        g[i][v] = true;
                    }
                }
            }
        }
    }
}
bool find_edge(int x){
    for(int i = head[x]; i!= -1; i = edge[i].next){
        int v = edge[i].to;
        if(g[x][v] == true && !vis[v]){
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
    int res, ans = 0;
    while(1){
        memset(link, 0, sizeof(link));
        res = Magyar(n);
        if(res == n){
            ans++;
            for(int i=1;i<=n;i++){
                g[link[i]][i]=false;
            }
        }
        else{
            break;
        }
    }
    return ans;
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
