#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 207;
const int maxm = 30007;
const int inf = 0x3f3f3f3f;
int n, m;
int slack[maxn], cntx, cnty, edge[maxn][maxn];
bool visx[maxn], visy[maxn];
int linkx[maxn], link[maxn], wx[maxn], wy[maxn];
bool dfs(int x){ //匈牙利算法找增广路径
    visx[x] = true;
    for(int i = 1; i <= cnty; i++){
        if(!visy[i]){
            int t = wx[x] + wy[i] - edge[x][i];
            if(t == 0) {
                visy[i] = true;
                if(link[i] == 0 || dfs(link[i])){
                    linkx[x] = i;
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
    memset(linkx, 0, sizeof linkx); //linkx[i]表示与X部中点i匹配的点
    memset(link, 0, sizeof link);
    memset(wy, 0, sizeof(wy));
    for(int i = 1; i <= cntx; i++){
        wx[i] = -inf;
        for(int j = 1; j <= cnty; j++){
            if(wx[i] < edge[i][j]){
                wx[i] = edge[i][j];//初始化为权值最大的边的权值
            }
        }
    }
    for(int i = 1; i <= cntx; i++){
        for(int j = 1; j <= cnty; j++){
            slack[j] = inf;
        }
        while(1){
            memset(visx, false, sizeof visx);
            memset(visy, false, sizeof visy);
            if(dfs(i)){
                break;
            }
            int minD=inf;
            for(int j = 1;j <= cnty; j++){
                if(!visy[j] && minD > slack[j]){
                    minD=slack[j];
                }
            }
            for(int j = 1; j <= cntx; j++){  //将交错树中X部的点的顶标减去minz
                if(visx[j]){
                    wx[j] -= minD;
                }
            }
            for(int j = 1; j <= cnty; j++){ //将交错树中Y部的点的顶标加上minz
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
    for(int i = 1; i <= cnty; i ++){
        if(link[i]!=0&&edge[link[i]][i]!=-inf){
            ans += edge[link[i]][i];
        }
        else{
            return -1;
        }
    }
    return -ans;
}
int main(){
    while(~scanf("%d%d", &n, &m)){
        cntx = cnty = n;
        for(int i = 0; i <= cntx; i++){
            for(int j = 0; j <= cnty; j++){
                edge[i][j] = -inf;
            }
        }
        for(int i = 0; i < m; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            edge[u][v] = max(edge[u][v], -w);
        }
        printf("%d\n", km());
    }
    return 0;
}
