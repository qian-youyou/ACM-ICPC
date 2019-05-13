#include<bits/stdc++.h>
#define N 105
int res[N];//存储源点到每个顶点的最短距离值
int g[N][N];
int cnt[N];//每个点入队次数，判断是否出现负环
int que[N*N];//队列
bool in_que[N];//标记一个点是否已在队列中
int front;//队首位置
int rear;//队尾位置
void spfa(int n,int src)
{
    rear=front=0;
    que[++rear]=src;
    memset(res,0x3f3f3f3f,sizeof(res));
    memset(in_que,0,sizeof(in_que));
    res[src]=0;
    while(front<rear)
    {
        int cur=que[++front];
        in_que[cur]=0;
        int i;
        for(i=1; i<=n; i++)
        {
            if(res[cur]+g[cur][i]<res[i])
            {
                res[i]=res[cur]+g[cur][i];
                if(!in_que[i])
                {
                    que[++rear]=i;
                    in_que=1;
                }
            }
        }
    }
}

int i,j,k;
for(k=0; k<n; k++)
{
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            g[i][j]=min(g[i][j],g[i][k]+g[k][j]);//g 为表示图的邻接矩阵
        }
    }
}

struct Edge{
    int x;  //端点1
    int y;  //端点2
    int l;  //长度
}edge[N];

int cmp(Edge a, Edge b){
    return a.l<b.l;
}
sort(edge, edge+m,cmp);
int main()
{
    return 0;
}
