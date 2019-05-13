#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
using namespace std;
const int maxn=1e5;
const int inf=1e9;
struct edge
{
    int to,cap,cost ,rev;
};
int V;
vector<edge>G[maxn];
int dist[maxn];
int prevv[maxn],preve[maxn];
void add(int from,int to,int cap,int cost)
{
    edge e,w;
    e.to=to;
    e.cap=cap;
    e.cost=cost;
    e.rev=G[to].size();
    G[from].push_back(e);
    w.to=from;
    w.cap=0;
    w.cost=-cost;
    w.rev=G[from].size()-1;
    G[to].push_back(w);
}
int min_ans(int s,int t,int f)
{
    int res=0;

    while(f>0)
    {
        for(int i=0; i<V; i++)
        {
            dist[i]=inf;
        }
        dist[s]=0;
        bool update=true;
        while(update)
        {

            update=false;
            for(int v=0; v<V; v++)
            {
                if(dist[v]==inf)
                {
                    continue;
                }
                for(int i=0; i<G[v].size(); i++)
                {
                    edge &e=G[v][i];
                    if(e.cap>0&&dist[e.to]>dist[v]+e.cost)
                    {
                        dist[e.to]=dist[v]+e.cost;
                        prevv[e.to]=v;
                        preve[e.to]=i;
                        update=true;
                    }
                }
            }
        }
        if(dist[t]==inf)
            return -1;
        int d=f;
        for(int v=t; v!=s; v=prevv[v])
        {
            d=min(d,G[prevv[v]][preve[v]].cap);
        }
        f-=d;
        res+=d*dist[t];
        for(int v=t; v!=s; v=prevv[v])
        {
            edge &e =G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
    return res;
}
int N,M;
int main()
{
    int a,b,c;
    while(cin>>N>>M)
    {
        V=N;
        for(int i=0; i<=N; i++)
            G[i].clear();
        for(int i=0; i<M; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            a--;
            b--;
            add(a,b,1,c);
            add(b,a,1,c);
        }
        printf("%d\n",min_ans(0,N-1,2));
    }
    return 0;
}
