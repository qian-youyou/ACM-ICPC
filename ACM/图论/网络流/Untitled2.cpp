#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>

using namespace std;
const int MAXN=1e5+5;
const int inf=1e9+7;
int n,m;
int s,e;
int X[MAXN],Y[MAXN];
struct node
{
    int u,v,f;
    int next;
} edge[MAXN<<1];

int head[MAXN];
int cnt;
void add(int u,int v,int f)
{
    edge[cnt].u=u;
    edge[cnt].v=v;
    edge[cnt].f=f;
    edge[cnt].next=head[u];
    head[u]=cnt++;
    edge[cnt].u=v;
    edge[cnt].v=u;
    edge[cnt].f=f;
    edge[cnt].next=head[v];
    head[v]=cnt++;
}

int dis[MAXN];
int bfs(int s,int t)
{
    int u, v ;
    memset(dis,-1,sizeof(dis));
    dis[s] = 0 ;
    queue<int>q;
    q.push(s) ;
    while( !q.empty() )
    {
        u = q.front();
        q.pop();
        for(int i = head[u] ; i != -1 ; i = edge[i].next)
        {
            v = edge[i].v ;
            if( dis[v] == -1 && edge[i].f )
            {
                dis[v] = dis[u] + 1 ;
                q.push(v) ;
            }
        }
    }
    if( dis[t] > 0 )
        return 1 ;
    return 0 ;
}
int dfs(int s,int t,int min1)
{
    if( s == t )
        return min1 ;
    int  flow, ans = 0 ;
    for(int i = head[s] ; i != -1 ; i = edge[i].next)
    {
        int v = edge[i].v ;
        if( dis[v] == dis[s] + 1 && edge[i].f && (flow = dfs(v,t,min(min1,edge[i].f) ) ) )
        {
            edge[i].f -= flow ;
            edge[i^1].f += flow ;
            ans += flow ;
            min1 -= flow ;
            if( !min1 )
                break;
        }
    }
    if( ans )
        return ans ;
    dis[s] = -1 ;
    return 0;
}
int getMaxFlow()
{
    int maxFlow=0,flow;
    while(bfs(s,e))
    {
        while((flow=dfs(s,e,inf))>0)
            maxFlow+=flow;
    }
    return maxFlow;
}
void read(){
        scanf("%d%d",&n,&m);
        int lp = inf,rp = -inf;
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d%d",&X[i],&Y[i]);
            if(X[i] < lp)lp = X[i],s = i;
            if(X[i] > rp)rp = X[i],e = i;
        }
        int u,v,f;
        cnt = 0;
        for(int i = 1; i <= n; ++i)head[i] = -1;
            for(int i = 0; i < m; ++i)
        {
            scanf("%d%d%d",&u,&v,&f);
            add(u,v,f);
        }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        read();

        printf("%d\n",getMaxFlow());
    }
    return 0;
}
