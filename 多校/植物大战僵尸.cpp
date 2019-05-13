#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <queue>
#define inf 0x3f3f3f3f
#define M 1000
using namespace std;
int now,tot,s,t,va[M],du[M],H[M],h[M],ok[M],d[M],v[M],cur[M];
int n,m;
queue<int> q;
struct edge1
{
	int x,y,ne;
}e[500000];
struct edge
{
	int from,to,cap,flow,ne;
}E[500000];
int C(int x,int y)
{
	return (x-1)*m+y;
}
void Add(int x,int y)
{
	e[++tot].y=y;
	e[tot].x=x;
	e[tot].ne=H[x];
	H[x]=tot;
	du[y]++;
}
void Addedge(int from,int to,int cap)
{
	E[++tot]=(edge){from,to,cap,0,h[from]};
	h[from]=tot;
	E[++tot]=(edge){to,from,0,0,h[to]};
	h[to]=tot;
}
bool bfs()
{
	for (int i=s;i<=t;i++)
		v[i]=0;
	v[s]=1;
	d[s]=0;
	q.push(s);
	while (!q.empty())
	{
		int x=q.front();
		q.pop();
		for (int i=h[x];i;i=E[i].ne)
		{
			edge e=E[i];
			if (!v[e.to]&&e.cap>e.flow)
			{
				v[e.to]=1;
				d[e.to]=d[x]+1;
				q.push(e.to);
			}
		}
	}
	return v[t];
}
int dfs(int x,int a)
{
	if (x==t||!a) return a;
	int flow=0;
	for (int &i=cur[x];i;i=E[i].ne)
	{
		edge &e=E[i];
		if (d[e.to]!=d[x]+1) continue;
		int f=dfs(e.to,min(a,e.cap-e.flow));
		if (f)
		{
			flow+=f;
			a-=f;
			e.flow+=f;
			E[i^1].flow-=f;
			if (!a) break;
		}
	}
	return flow;
}
int dinic()
{
	int flow=0;
	while (bfs())
	{
		for (int i=s;i<=t;i++)
			cur[i]=h[i];
		flow+=dfs(s,inf);
	}
	return flow;
}
void Topsort()
{
	queue<int> q;
	for (int i=1;i<=now;i++)
		if (!du[i]) ok[i]=1,q.push(i);
	while (!q.empty())
	{
		int x=q.front();
		q.pop();
		for (int i=H[x];i;i=e[i].ne)
		{
			int y=e[i].y;
			du[y]--;
			if (!du[y])
			{
				ok[y]=1;
				q.push(y);
			}
		}
	}
}
int main()
{
    scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			now++;
			int w;
			scanf("%d%d",&va[now],&w);
			for (int k=1;k<=w;k++)
			{
				int x,y;
				scanf("%d%d",&x,&y);
				x++,y++;
				Add(now,C(x,y));
			}
			if (j!=m) Add(now+1,now);
		}
	Topsort();
	s=0,t=now+1;
	int ans=0;
	tot=1;
	for (int x=1;x<=now;x++)
		if (ok[x])
		{
			if (va[x]>0) ans+=va[x],Addedge(s,x,va[x]);
			else Addedge(x,t,-va[x]);
			for (int i=H[x];i;i=e[i].ne)
			{
				int y=e[i].y;
				if (ok[y])
					Addedge(y,x,inf);
			}
		}
	cout<<ans-dinic()<<endl;
	return 0;
}
