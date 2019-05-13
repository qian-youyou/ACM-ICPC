#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
int cnt=2;
int alist[6000001];
struct data{
    int v;int next;int value;
}edge[6000001];
void add(int u,int v,int value)
{
    edge[cnt].v=v;
    edge[cnt].value=value;
    edge[cnt].next=alist[u];
    alist[u]=cnt++;
    return ;
}
int h[1000001];
int q[1000001];
//dicnic暴力参见上面提到的博客。
bool bfs()
{
    int x,next;
    memset(h,-1,sizeof(h));
    int head=0,tail=1;
    q[head]=1;
    h[1]=0;
    while(head<tail)
    {
        x=q[head++];
        next=alist[x];
        while(next)
        {
            int v=edge[next].v;
            int value=edge[next].value;
            if(value&&h[v]<0)
            {
                q[tail++]=v;
                h[v]=h[x]+1;
            }
            next=edge[next].next;
        }
    }
    for(int i=1;i<=n*m;i++) printf("h[%d]=%d\n",i,h[i]);
    if(h[n]==-1) return false;
    return true;
}
int ans;
int dfs(int x,int y)
{
    if(x==n) return y;
    int next=alist[x];
    int w,used=0;
    while(next)
    {
        int v=edge[next].v;
        int value=edge[next].value;
        if(value&&h[v]==h[x]+1)
        {
                w=y-used;
                w=dfs(v,min(w,value));
                edge[next].value-=w;
                edge[next^1].value+=w;
                used+=w;
                if(used==y) return y;
        }
        next=edge[next].next;
    }
    if(!used) h[x]=-1;
    return used;
}
void dinic()
{
    while(bfs()) ans+=dfs(1,0x3f3f);
}
int n1,m1,e1;
int main()
{
 //   freopen("testdata.in","r",stdin);
 //第一遍没A就是因为忘了删上面这句话。。。
    scanf("%d%d%d",&n1,&m1,&e1);
    n=n1+m1+2;

    for(int i=1;i<=e1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(u<=n1&&v<=m1)
        add(u+1,v+n1+1,1),
        add(v+n1+1,u+1,1);
    }
    for(int i=1;i<=m1;i++)
    {
        add(i+n1+1,n,1);
        add(n,i+n1+1,1);
    }
    dinic();//暴力跑最大流
    printf("%d",ans);
    return 0;//程序拜拜
}
