#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn = 107;
const int inf = 0x3f3f3f3f;
struct EDGE{
    int c;
    int w;
}edge[57][maxn][maxn];
int n, m, k, sx, ex, num, N;
int cnt, dis[maxn], pre[maxn], st[57], et[57];
bool vis[maxn];
void add(int k, int u, int v, int c, int w){
    edge[k][u][v].c += c;
    if(edge[k][u][v].c > inf){
        edge[k][u][v].c = inf;
    }
    edge[k][u][v].w += w;
}
void init(){
    sx = 0;
    ex = n+m+1;
    memset(edge, 0, sizeof(edge));
    memset(st, 0, sizeof(st));
    memset(et, 0, sizeof(et));
    N = ex;
}
void read(){
    int tmp;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            scanf("%d",&tmp);
            st[j]+=tmp;
            add(j,i,ex,tmp,0);
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= k; j++){
            scanf("%d",&tmp);
            et[j]+=tmp;
            add(j,sx,n+i,tmp,0);
        }
    }
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++){
            for(int e = 1; e <= m; e++){
                scanf("%d",&tmp);
                add(i,n+e,j,inf,tmp);
            }
        }
    }
}
bool SPFA(int k, int sx, int ex){
    memset(vis, false, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    memset(dis, inf, sizeof(dis));
    queue<int>que;
    que.push(sx);
    dis[sx] = 0;
    while(!que.empty()){
        int kk = que.front();
        que.pop();
        vis[kk] = false;
        for(int i = 1; i <= N; i++){
            if(edge[k][kk][i].c){
                if(dis[i]>edge[k][kk][i].w + dis[kk]){
                    dis[i] = edge[k][kk][i].w + dis[kk];
                    pre[i] = kk;
                    if(!vis[i]){
                        vis[i] = true;
                        que.push(i);
                    }
                }
            }
        }
    }
    return pre[ex]!=-1;
}
int MCMF(int k, int sx, int ex){
    int i, min_flow, flow = 0, cost = 0;
    while(SPFA(k, sx, ex)){
        min_flow = inf;
        for(i = ex; pre[i]!=-1; i = pre[i]){
            min_flow = min(edge[k][pre[i]][i].c, min_flow);
        }
        for(i = ex; pre[i]!=-1; i=pre[i]){
            edge[k][pre[i]][i].c -= min_flow;
            edge[k][i][pre[i]].c += min_flow;
            cost += edge[k][pre[i]][i].w * min_flow;
        }

        flow += min_flow;
    }
    return cost;
}
void solve(){
    int ans = 0;
    for(int i = 1;i<=k;i++){
        int cost = MCMF(i,sx, ex);
        if(et[i]<st[i]){
            printf("-1\n");
            return;
        }
        ans+=cost;
    }
    printf("%d\n",ans);
}
int main(){
    while(~scanf("%d%d%d",&n,&m,&k)){
        if(!(n+m+k))
            break;
        init();
        read();
        solve();
    }
    return 0;
}
