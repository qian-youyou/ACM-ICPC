#include<bits/stdc++.h>
using namespace std;
const int maxn=1001;
int n,m,k;
int a[maxn],b[maxn],t[maxn][maxn],vis[maxn];
int dfs(int u)
{
    for(int i=1;i<=m;i++)
    {
        if(t[u][i]==1&&vis[i]==0)
        {
            vis[i]=1;
            if(b[i]==0||dfs(b[i]))
            {
                a[u]=i;
                b[i]=u;
                return 1;
            }
        }
    }
    return 0;
}
int main(void)
{
    int cnt=0;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<k;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        t[x][y]=1;
    }
    int j;
    for(int i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
    {if(t[i][j])
        break;
    }
    if(j>m)
       {

        cnt++; continue;
       }
            memset(vis,0,sizeof(vis));
            if(dfs(i)) cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
