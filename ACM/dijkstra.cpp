#include<bits/stdc++.h>
using namespace std;

const int maxn = 1007;
const int inf = 0x3f3f3f3f; //需将road及dis初始化为正无穷inf
int n;
int dis[maxn];  //储存各个点到源点的最短距离,dis[s]为0
int road[maxn][maxn];   //两点之间直接距离关系
bool vis[maxn];     //判断源点到该点的距离是否为最短距离
int dijkstra(int s, int e){
    int ans = -1;
    memset(vis, false, sizeof(vis));
    vis[s] = true;
    for(int i = 1;i <= n;i++)
        dis[i] = road[s][i];

    return ans;
}
int main(){
    cin>>n;
    memset(road,inf,sizeof(road));
    for(int i = 1;i<=n;i++)
    {
int tmp;
        int x,y;
        cin>>x>>y>>tmp;
        road[y][x]=road[x][y]=tmp;
    }
    cout<<dijkstra(1,n)<<endl;
    return 0;
}
