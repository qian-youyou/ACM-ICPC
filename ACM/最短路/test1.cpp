#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+9;
const int inf = 0x3f3f3f3f; //需将road及dis初始化为正无穷inf
int n,m,k,s;

int pre[maxn];//记录到达该点的上一个点的坐标
int dis[maxn];  //储存各个点到源点的最短距离,dis[s]为0
int road[maxn][maxn];  //两点之间直接距离关系
bool vis[maxn];     //判断源点到该点的距离是否为最短距离

void dijkstra(int s,int e)
{//s为起点，e为终点
    memset(vis, false, sizeof(vis));//标记是否求出最短路径
    vis[s] = true;//标记起点到这一点的最小距离已经求出
    for(int i = 1; i <= n; i++){
        dis[i] = road[s][i];//初始化起点到每一个点的距离
        pre[i]=s;//初始化路径，每个点的上一个点为起点
    }
    dis[s] = 0;
    for(int u = 1; u<n; u++)
    {
        int minD = inf,k = -1;
        for(int i = 1; i<= n; i++)
        {   //寻找没有访问过的最短路
            if(!vis[i]&&dis[i]<minD)
            {
                k = i;//记录下标
                minD = dis[i];//记录最小值
            }
        }
        if(k==-1)    break;
        vis[k] = true;//标记已经访问过
        //松弛操作
        for(int i = 1; i<= n; i++)
        {
            if(!vis[i]&&dis[k]+road[k][i]<dis[i])
            {
                dis[i]=dis[k]+road[k][i];
                pre[i]=k;
            }//if
        }//for
    }
}
void print(int cur)
{
    if(cur==1){
        printf("1");
        return;
    }
    print(pre[cur]);
    printf(" %d",cur);
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(road,inf,sizeof(road));
        memset(pre,0,sizeof(pre));
        for(int i=1;i<=m;i++)
        {
            int a,b,d;
            scanf("%d%d%d",&a,&b,&d);
            road[a][b]=min(d,road[a][b]);
            //起点是fans[i],终点是S
        }
        dis[1]=0;//起点
        dijkstra(1,n);
            //if(dis[n]==inf)    printf("-1");
            //else   {
                for(int i=1;i<=n;i++)
                    printf("dis=%d\n%d:%d\n",dis[i],i,pre[i]);
                print(n);
            //}
            printf("\n");
        }
    return 0;
}
