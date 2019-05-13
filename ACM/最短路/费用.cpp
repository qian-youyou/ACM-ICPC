#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
#define Min(a,b) a>b?b:a
struct Node
{
	int adj,val;
}g[1005][1005];
int dist[1005];//����
int value[1005];//����
int used[1005];//���
int n,m,i,j;
void Dijkstra(int s)
{
	memset(dist,0x3f,sizeof(dist));
	memset(value,0x3f,sizeof(value));
	memset(used,0,sizeof(used));
	dist[s]=0;//����㿪ʼ
	value[s]=0;
	while(1)
	{
		int k,u=-1,d[1005];
		int min=INF;
		memset(d,0,sizeof(d));
		for(i=1;i<=n;i++)
			if(used[i]==0&&dist[i]<min)//�ҳ�����㵽��һ����С����Ķ���
			{
				min=dist[i];
				u=i;//��¼�±�
			}
		if(u==-1)//�ж����ж����Ƿ񶼵����
			return ;
		for(i=1,k=0;i<=n;i++)
			if(dist[u]==dist[i]&&used[i]==0)
				d[k++]=i;//����㵽��һ��Ҫ���ʵĶ������С��������ж��
		for(i=0;i<k;i++)
			used[d[i]]=1;
		for(i=0;i<k;i++)//�������ĵ�ֱ���еϽ�˹�������·����
			for(j=1;j<=n;j++)
				if(g[d[i]][j].adj!=INF && (dist[d[i]]+g[d[i]][j].adj)<=dist[j])
				{//ԭ���� main()�����н����ڽӾ���һ��
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
			if(d<=g[a][b].adj)//����·����������
			{
				if(d==g[a][b].adj)//���������ȣ��������ٵķ���
					g[a][b].val=g[b][a].val=Min(p,g[a][b].val);
				else//���򣬴����·������ķ���
					g[a][b].val=g[b][a].val=p;
				g[a][b].adj=g[b][a].adj=d;//���·������
			}
		}
		int s,t;
		scanf("%d%d",&s,&t);
		Dijkstra(s);
		printf("%d %d\n",dist[t],value[t]);
	}
	return 0;
}
