#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+7;
const int inf = 0x3f3f3f3f;
int n,m;
struct node{
    int a;
    int b;
};
int f[maxn];
int dis[maxn];
vector<node>road[maxn];
bool vis[maxn];
void dijkstra()
{
    memset(f, -1, sizeof(f));
    memset(vis, false, sizeof(vis));
    memset(dis, inf, sizeof(dis));
    vis[1] = true;
    for(vector<node>::iterator it = road[1].begin(); it != road[1].end(); it++)
    {
        f[(*it).a] = (*it).b;
        dis[(*it).a] = 1;
    }
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
        int ttt = -1;
        for(vector<node>::iterator it = road[k].begin(); it != road[k].end(); it++)
        {
            if(!vis[(*it).a])
            {
                if((*it).b==f[k])
                    dis[(*it).a] = dis[k];
                else if(dis[k]+1<dis[(*it).a]){
                    dis[(*it).a]=dis[k]+1;
                    f[(*it).a] = (*it).b;
                }
            }
        }
    }
}
int main()
{
    while(cin>>n>>m)
    {
        for(int i = 1;i<=n;i++){
            road[i].clear();
        }
        memset(road,-1,sizeof(road));
        for(int i = 1; i<=m; i++)
        {
            int x,y,tmp;
            cin>>x>>y>>tmp;
            node temp;
            temp.a = y,temp.b = tmp;
            road[x].push_back(temp);
            temp.a = x;
            road[y].push_back(temp);
        }
        dijkstra();
        if(dis[n]!=inf)
            cout<<dis[n]<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
