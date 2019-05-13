#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
#define Min(a,b) a>b?b:a
struct Node
{
	int adj,val;
}g[1005][1005];
int dist[1005];//距离
int value[1005];//费用
int used[1005];//标记
int n,m,i,j;
void Dijkstra(int s)
{
	memset(dist,0x3f,sizeof(dist));
	memset(value,0x3f,sizeof(value));
	memset(used,0,sizeof(used));
	dist[s]=0;//从起点开始
	value[s]=0;
	while(1)
	{
		int k,u=-1,d[1005];
		int min=INF;
		memset(d,0,sizeof(d));
		for(i=1;i<=n;i++)
			if(used[i]==0&&dist[i]<min)//找出从起点到下一个最小距离的顶点
			{
				min=dist[i];
				u=i;//记录下标
			}
		if(u==-1)//判断所有顶点是否都到达过
			return ;
		for(i=1,k=0;i<=n;i++)
			if(dist[u]==dist[i]&&used[i]==0)
				d[k++]=i;//从起点到下一个要访问的顶点的最小距离可能有多个
		for(i=0;i<k;i++)
			used[d[i]]=1;
		for(i=0;i<k;i++)//多个满足的点分别进行迪杰斯特拉最短路查找
			for(j=1;j<=n;j++)
				if(g[d[i]][j].adj!=INF && (dist[d[i]]+g[d[i]][j].adj)<=dist[j])
				{//原理与 main()函数中建立邻接矩阵一样
					if((dist[d[i]]+g[d[i]][j].adj)<dist[j])
						value[j]=value[d[i]]+g[d[i]][j].val;
					else
						value[j]=Min(value[j],value[d[i]]+g[d[i]][j].val);
					dist[j]=dist[d[i]]+g[d[i]][j].adj;
				}
	}
}
int main()
{
	while(scanf("%d%d",&n,&m) && (n||m))
	{
		int a,b,d,p;
		memset(g,0x3f,sizeof(g));
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d%d",&a,&b,&d,&p);
			if(d<=g[a][b].adj)//处理路径距离问题
			{
				if(d==g[a][b].adj)//如果距离相等，则存放最少的费用
					g[a][b].val=g[b][a].val=Min(p,g[a][b].val);
				else//否则，存放新路径距离的费用
					g[a][b].val=g[b][a].val=p;
				g[a][b].adj=g[b][a].adj=d;//填充路径距离
			}
		}
		int s,t;
		scanf("%d%d",&s,&t);
		Dijkstra(s);
		printf("%d %d\n",dist[t],value[t]);
	}
	return 0;
}
