#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+7;
const int inf = 0x3f3f3f3f;
int n, m, sx, ex, cnt;
int head[maxn], pre[maxn];
struct EDGE{
    int u, next, to, c;
}edge[maxn<<1];
void add_edge(int u, int v, int c){
    edge[cnt].u = u;
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].c = c<=inf ? c : inf;
    head[u] = cnt++;
}
void add(int u, int v, int c){
    add_edge(u, v, c);
    add_edge(v, u, c);
}
int bfs(int s,int t)
{
    int u, v ;
    memset(pre,-1,sizeof(pre));
    pre[s] = 0 ;
    queue<int>q;
    q.push(s) ;
    while( !q.empty() )
    {
        u = q.front();
        q.pop();
        for(int i = head[u] ; i != -1 ; i = edge[i].next)
        {
            v = edge[i].to ;
            if( pre[v] == -1 && edge[i].c )
            {
                pre[v] = pre[u] + 1 ;
                q.push(v) ;
            }
        }
    }
    if( pre[t] > 0 )
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
        int v = edge[i].to ;
        if( pre[v] == pre[s] + 1 && edge[i].c && (flow = dfs(v,t,min(min1,edge[i].c) ) ) )
        {
            edge[i].c -= flow ;
            edge[i^1].c += flow ;
            ans += flow ;
            min1 -= flow ;
            if( !min1 )
                break;
        }
    }
        return ans ;
    pre[s] = -1 ;
    return 0;
}
int Dinic()
{
    int maxFlow=0,flow;
    while(bfs(sx,ex))
    {
        while((flow=dfs(sx,ex,inf))>0)
            maxFlow+=flow;
    }
    return maxFlow;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        cnt = 0;
    int x,y;
    scanf("%d%d",&n, &m);
    int min_a = inf, max_a = -inf;
    sx = ex = 0;
    for(int i = 1; i <= n; ++i){
        head[i] = -1;
        scanf("%d%d", &x, &y);
        if(min_a > x){
            min_a = x;
            sx = i;
        }
        if(max_a < x){
            max_a = x;
            ex = i;
        }
    }
    for(int i = 0; i < m; ++i){
        int u, v, w;
        scanf("%d%d%d",&u, &v, &w);
        add(u, v, w);
    }
        printf("%d\n", Dinic());
    }
    return 0;
}
