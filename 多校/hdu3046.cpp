#include<bits/stdc++.h>
#define maxn 100100
#define inf 99999999
using namespace std;

int to[maxn],c[maxn],first[maxn],Next[maxn],N;
int d[maxn];
int s,t,n,m,tmp,ans,cas=0;
int Q[maxn],bot,top,tag[maxn],can[maxn],TAG=423;

void _init()
{
    ans=s=0,t=n*m+1,N=-1;
    for (int i=s; i<=t; i++) first[i]=-1;
}

void edge(int U,int V,int W)
{
    N++;
    to[N]=V,c[N]=W;
    Next[N]=first[U],first[U]=N;
}

void _input()
{
    int cur=0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            scanf("%d",&tmp);
            cur++;
            if (i<n) edge(cur,cur+m,1),edge(cur+m,cur,1);
            if (j<m) edge(cur,cur+1,1),edge(cur+1,cur,1);
            if (tmp==2) edge(s,cur,inf),edge(cur,s,inf);
                else if (tmp==1) edge(cur,t,inf),edge(t,cur,inf);
        }

}

bool bfs()
{
    TAG++;
    Q[bot=top=1]=t,d[t]=0,tag[t]=TAG;
    while (bot<=top)
    {
        int cur=Q[bot++];
        for (int i=first[cur]; i!=-1; i=Next[i])
        {
            if (c[i^1]<=0 || tag[to[i]]==TAG) continue;
            tag[to[i]]=TAG,d[to[i]]=d[cur]+1,Q[++top]=to[i];
            if (to[i]==s) return true;
        }
    }
    return false;
}

int dfs(int cur,int num)
{
    if (cur==t) return num;
    int tmp=num,k;
    for (int i=first[cur]; i!=-1; i=Next[i])
    {
        if (d[cur]!=d[to[i]]+1 || c[i]<=0 || tag[to[i]]!=TAG || can[to[i]]==TAG) continue;
        k=dfs(to[i],min(num,c[i]));
        if (k) c[i]-=k,c[i^1]+=k,num-=k;
        if (num==0) break;
    }
    if (num) can[cur]=TAG;
    return tmp-num;
}

int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        _init();
        _input();
        while (bfs()) ans+=dfs(s,inf);
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
