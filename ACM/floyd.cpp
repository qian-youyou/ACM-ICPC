#include<bits/stdc++.h>
#define N 105
int res[N];//�洢Դ�㵽ÿ���������̾���ֵ
int g[N][N];
int cnt[N];//ÿ������Ӵ������ж��Ƿ���ָ���
int que[N*N];//����
bool in_que[N];//���һ�����Ƿ����ڶ�����
int front;//����λ��
int rear;//��βλ��
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
            g[i][j]=min(g[i][j],g[i][k]+g[k][j]);//g Ϊ��ʾͼ���ڽӾ���
        }
    }
}

struct Edge{
    int x;  //�˵�1
    int y;  //�˵�2
    int l;  //����
}edge[N];

int cmp(Edge a, Edge b){
    return a.l<b.l;
}
sort(edge, edge+m,cmp);
int main()
{
    return 0;
}
