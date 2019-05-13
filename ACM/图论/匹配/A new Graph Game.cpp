#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 1010;
const int inf = 0x3f3f3f3f;
int n, m;
int slack[maxn], edge[maxn][maxn];
bool visx[maxn], visy[maxn];
int link[maxn], wx[maxn], wy[maxn];
bool dfs(int x){ //匈牙利算法找增广路径
    visx[x] = true;
    for(int i = 1; i <= n; i++){
        if(!visy[i]){
            int t = wx[x] + wy[i] - edge[x][i];
            if(t == 0) {
                visy[i] = true;
                if(link[i] == 0 || dfs(link[i])){
                    link[i] = x;
                    return true;
                }
            }
            else if(t > 0){  //找出边权与顶标和的最小的差值
                slack[i] = min(slack[i], t);
            }
        }
    }
    return false;
}
int km(){
    memset(link, 0, sizeof link);
    memset(wy, 0, sizeof(wy));
    for(int i = 1; i <= n; i++){
        wx[i] = -inf;
        for(int j = 1; j <= n; j++){
            if(wx[i] < edge[i][j]){
                wx[i] = edge[i][j];//初始化为权值最大的边的权值
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            slack[j] = inf;
        }
        while(1){
            memset(visx, false, sizeof visx);
            memset(visy, false, sizeof visy);
            if(dfs(i)){
                break;
            }
            int minD=inf;
            for(int j = 1;j <= n; j++){
                if(!visy[j] && minD > slack[j]){
                    minD=slack[j];
                }
            }
            for(int j = 1; j <= n; j++){  //将交错树中X部的点的顶标减去minz
                if(visx[j]){
                    wx[j] -= minD;
                }
            }
            for(int j = 1; j <= n; j++){ //将交错树中Y部的点的顶标加上minz
                if(visy[j]){
                    wy[j] += minD;
                }
                else{
                    slack[j] -= minD;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++){
        if(link[i] == 0 || edge[link[i]][i]==-inf){
            return 0;
        }
        else{
            ans += edge[link[i]][i];
        }
    }
    return -ans;
}
int main(){
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas<=T; ++cas){
        scanf("%d%d", &n, &m);
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                edge[i][j] = -inf;
            }
        }
        for(int i = 0; i < m; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            edge[u][v] = max(edge[u][v], -w);
            edge[v][u] = max(edge[v][u], -w);
        }
        int ans = km();
        if(ans){
            printf("Case %d: %d\n", cas, ans);
        }
        else{
            printf("Case %d: NO\n", cas);
        }
    }
    return 0;
}
