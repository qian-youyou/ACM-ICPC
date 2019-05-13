#include<bits/stdc++.h>
using namespace std;
int A, B, C1, C2, n, sx, ex;
const int maxn = 1007;
const int inf = 0x3f3f3f3f;
struct NODE{
    int x, y, r;
}node[maxn];
struct CMB{
    int u;
    double dis;
    CMB(){}
    CMB(int u,double w):u(u),dis(w){}
	bool operator <(const CMB &a)const{
		return dis>a.dis;
	}
};
bool vis[maxn];
double dis[maxn];
double road[maxn][maxn];
void init(){
    sx = 0;
    ex = n + 1;
    for(int i = 0;i<=ex;i++){
        for(int j = 0;j<=ex;j++){
            road[i][j] = 9999999.0;
        }
        dis[i] = 9999999.0;
    }
    memset(vis, false, sizeof(vis));
    dis[sx] = 0;
    road[ex][sx] = road[sx][ex] = fabs((double)C1-C2)/sqrt((double)A*A+B*B);
}
void read(){
    for(int i = 1; i<=n; i++){
        scanf("%d%d%d", &node[i].x, &node[i].y, &node[i].r);
        double tmp_sx = fabs((double)(A*node[i].x+B*node[i].y+C1)/sqrt((double)A*A+B*B)) - node[i].r;
        double tmp_ex = fabs((double)(A*node[i].x+B*node[i].y+C2)/sqrt((double)A*A+B*B)) - node[i].r;
        road[sx][i] = road[i][sx] = tmp_sx>=0 ? tmp_sx : 0;
        road[ex][i] = road[i][ex] = tmp_ex>=0 ? tmp_ex : 0;
        for(int j = 1; j < i; j++){
            double tmp = sqrt((double)pow(node[i].x-node[j].x, 2) + pow(node[i].y-node[j].y, 2)) - node[i].r - node[j].r;
            road[j][i] = road[i][j] = tmp<0 ? 0 : tmp;
        }
    }
}
double dijkstra(){
    priority_queue<CMB>q;
    q.push(CMB(sx,0));
    while(!q.empty()){
        CMB top = q.top();
        q.pop();
        if(vis[top.u])
            continue;
        vis[top.u] = true;
        if(top.u == ex)
            return dis[ex];
        for(int i = 1; i <= ex; i++){
            if(!vis[i] && top.dis+road[top.u][i]<dis[i]){
                dis[i] = top.dis+road[top.u][i];
                q.push(CMB(i,dis[i]));
            }
        }
    }
    return dis[ex];
}
void solve(){
    printf("%.6lf\n",dijkstra());
}
int main(){
    while(~scanf("%d%d%d%d%d", &n, &A, &B, &C1, &C2)){
        init();
        read();
        solve();
    }
    return 0;
}
