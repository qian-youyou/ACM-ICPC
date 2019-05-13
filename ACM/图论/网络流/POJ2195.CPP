#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <bitset>

using namespace std;

#define LL long long
const int INF = 0x3f3f3f3f;
#define MAXN 60100
#define MAXM 1000100

int vis[MAXN],d[MAXN],pre[MAXN],a[MAXN];

struct Edge
{
	int u, v, c, cost, next;
} edge[MAXM];
int s[MAXN], cnt;

void init()
{
	cnt = 0;
	memset(s, -1, sizeof(s));
}

void add(int u, int v, int c, int cost)
{
	edge[cnt].u = u;
	edge[cnt].v = v;
	edge[cnt].cost = cost;
	edge[cnt].c = c;
	edge[cnt].next = s[u];
	s[u] = cnt++;
	edge[cnt].u = v;
	edge[cnt].v = u;
	edge[cnt].cost = -cost;
	edge[cnt].c = 0;
	edge[cnt].next = s[v];
	s[v] = cnt++;
}

bool spfa(int ss, int ee,int &flow,int &cost)
{
	queue<int> q;
	memset(d, INF, sizeof d);
	memset(vis, 0, sizeof vis);
	d[ss] = 0, vis[ss] = 1, pre[ss] = 0, a[ss] = INF;
	q.push(ss);
	while (!q.empty())
	{
		int u = q.front();q.pop();
		vis[u] = 0;
		for (int i = s[u]; ~i; i = edge[i].next)
		{
			int v = edge[i].v;
			if (edge[i].c>0&& d[v]>d[u] + edge[i].cost)
			{
				d[v] = d[u] + edge[i].cost;
				pre[v] = i;
				a[v] = min(a[u], edge[i].c);
				if (!vis[v])
				{
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
	if (d[ee] == INF) return 0;
	flow += a[ee];
	cost += d[ee]*a[ee];
	int u = ee;
	while (u != ss)
	{
		edge[pre[u]].c -= a[ee];
		edge[pre[u] ^ 1].c += a[ee];
		u = edge[pre[u]].u;
	}
	return 1;
}

int MCMF(int ss, int ee)
{
	int cost = 0, flow=0;
	while (spfa(ss, ee, flow, cost));
	return cost;
}

struct point{
int x,y;
};

int main()
{
	  char mp[105][105];
    int m,n;
    while(~scanf("%d%d",&n,&m)&&(m||n))
    {
        point H[105],P[105];
        int h=0,p=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",&mp[i]);
            for(int j=0;j<m;j++)
            {
                if(mp[i][j]=='#')
                {
                   H[h].x=i;
                   H[h].y=j;
                   h++;
                }
                else if(mp[i][j]=='@')
                {
                    P[p].x=i;
                    P[p].y=j;
                    p++;
                }
            }
        }
        init();
        for(int i=0;i<h;i++)
            for(int j=0;j<p;j++)
        {
            int c=fabs(H[i].x-P[j].x)+fabs(H[i].y-P[j].y);
             add(i+1,h+j+1,1,c);
        }

        for(int i=0;i<h;i++)
        {
            add(0,i+1,1,0);
        }
        for(int i=0;i<p;i++)
        {
            add(h+1+i,h+p+1,1,0);
        }
        printf("%d\n",MCMF(0,h+p+1));

    }
	return 0;
}
