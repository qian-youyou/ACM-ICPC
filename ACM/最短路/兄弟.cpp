#include<bits/stdc++.h>
using namespace std;

const int maxn = 107;
const int inf = 0x3f3f3f3f; //需将road及dis初始化为正无穷inf
int n,m,k,s;
int dis[maxn];  //储存各个点到源点的最短距离,dis[s]为0
int road[maxn][maxn];   //两点之间直接距离关系
bool vis[maxn];     //判断源点到该点的距离是否为最短距离
int fans[maxn];
void dijkstra(int s)
{
    memset(vis, false, sizeof(vis));
    vis[s] = true;
    for(int i = 1; i <= n; i++)
        dis[i] = road[s][i];
    for(int u = 1; u<n; u++)
    {
        int minD = inf,k = -1;
        for(int i = 1; i<= n; i++)
        {
            if(!vis[i]&&dis[i]<minD)
            {
                k = i;
                minD = dis[i];
            }
        }
        vis[k] = true;
        for(int i = 1; i<= n; i++)
        {
            if(!vis[i]&&dis[k]+road[k][i]<dis[i])
            {
                dis[i]=dis[k]+road[k][i];
            }
        }
    }
}
int main()
{
    cin>>n>>m>>k>>s;
    memset(road,inf,sizeof(road));
    for(int i = 1; i<=m; i++)
    {
        int tmp;
        int x,y;
        cin>>x>>y>>tmp;
        road[y][x]=tmp;
    }
    dijkstra(s);
    for(int i = 0; i<k; i++)
    {
        cin>>fans[i];
    }
    for(int i = 0; i<k-1; i++)
        cout<<dis[fans[i]]<<' ';
    cout<<dis[fans[k-1]]<<endl;
    return 0;
}
