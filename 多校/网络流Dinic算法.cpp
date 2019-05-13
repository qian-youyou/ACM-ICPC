#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
#define min(a,b)(a<b?a:b)
#define INF 1000000
const int MAX=210;
struct Node
{
    int c;
    int f;
};
int sx,ex;//sx和ex分别代表源点和汇点
int pre[MAX];
Node map[MAX][MAX];
int n,m;
bool BFS()//BFS搜索层次网络
{
     memset(pre,0,sizeof(pre));
    queue< int > Q;
    Q.push(sx);
    pre[sx]=1;
    while(!Q.empty())
    {
        int d=Q.front();
        Q.pop();
        for(int i=1;i<=n;i++)
        {
            if(!pre[i]&&map[d][i].c-map[d][i].f)
            {
                pre[i]=pre[d]+1;
                Q.push(i);
            }
        }
    }
    return pre[ex]!=0;

}
int dfs(int pos,int flow)//pos是顶点号，flow是当前顶点所能得到的流量
{
    int f=flow;
    if(pos==ex)
    return flow;
    for(int i=1;i<=n;i++)
    {
        if(map[pos][i].c-map[pos][i].f&&pre[pos]+1==pre[i])
        {
            int a=map[pos][i].c-map[pos][i].f;
            int t=dfs(i,min(a,flow));
            map[pos][i].f+=t;
            map[i][pos].f-=t;
            flow-=t;//我最开始就是这里没弄明白，为什么要此顶点得到的流量减去改变量；答案就在下面的  return f-flow;
        }
    }
    return f-flow;//其实这里返回给他前一层的就是这个t;因为t在层函数里面都有，所以所过避免重复就写成这样；

}
int dinic()
{
    int sum=0;
    while(BFS())
    {
        sum+=dfs(sx,INF);
    }
    return sum;
}
int main()
{
    int u,v,w;
    while(cin>>m>>n)
    {
        sx=1;
        ex=n;
       memset(map,0,sizeof(map)) ;
       for(int i=1;i<=m;i++)
       {
           cin>>u>>v>>w;
           map[u][v].c+=w;
       }
       cout<<dinic()<<endl;
    }
    return 0;
}
