#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
const int maxn=510;
int graph[maxn][maxn];//保存图
int degree[maxn];//保存入度

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(graph,0,sizeof(graph));
        memset(degree,0,sizeof(degree));
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            if(!graph[u][v])
            {
                graph[u][v]=1;
                degree[v]++;//的入度++
            }
        }
        priority_queue<int,vector<int>,greater<int> >q;
        for(int i=1;i<=n;i++)
            if(degree[i]==0)
            q.push(i);
        bool first=1;
        while(!q.empty())
        {
            int cur=q.top();
            q.pop();
            if(first)
            {
                cout<<cur;
                first=0;
            }
            else
                cout<<" "<<cur;
            for(int i=1;i<=n;i++)
            {
                if(graph[cur][i]==1)
                {
                    degree[i]--;//相连的点的入度减1
                    if(degree[i]==0)//假设入度为0，增加队列
                        q.push(i);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
