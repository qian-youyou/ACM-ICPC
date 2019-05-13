#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;

const int max_n=205;
const int max_m=205;
const int max_e=max_m*2;
const int inf=1e9;

int point[max_n],next[max_e],v[max_e],remain[max_e],tot;
int cur[max_n],deep[max_n],last[max_n],num[max_n];
int n,m,x,y,cap,maxflow;
queue <int> q;

inline void add(int x,int y,int cap){
    ++tot; next[tot]=point[x]; point[x]=tot; v[tot]=y; remain[tot]=cap;
    ++tot; next[tot]=point[y]; point[y]=tot; v[tot]=x; remain[tot]=0;
}

inline void bfs(int t){
    for (int i=1;i<=n;++i)
      deep[i]=n;
    deep[t]=0;
    while (!q.empty()) q.pop();
    q.push(t);

    while (!q.empty()){
        int now=q.front(); q.pop();
        for (int i=point[now];i!=-1;i=next[i])
          if (deep[v[i]]==n&&remain[i^1]){
            deep[v[i]]=deep[now]+1;
            q.push(v[i]);
          }
    }
}

inline int addflow(int s, int t) {
    int ans=inf,now=t;
    while (now!=s) {
        ans=min(ans, remain[last[now]]);
        now=v[last[now] ^ 1];
    }
    now=t;
    while (now != s) {
        remain[last[now]]-=ans;
        remain[last[now]^1]+=ans;
        now=v[last[now]^1];
    }
    return ans;
}

inline void isap(int s,int t){
    int now=s;
    bfs(t);
    for (int i=1;i<=n;++i) ++num[deep[i]];
    for (int i=1;i<=n;++i) cur[i]=point[i];

    //在残量网络中没有源点到汇点的通路
    while (deep[s]<n){
        //如果到达汇点则进行增广，重新回到源点准备下一轮增广
        if (now==t){
            maxflow+=addflow(s,t);
            now=s;
        }

        bool has_find=false;
        //当前弧优化
        for (int i=cur[now];i!=-1;i=next[i]){
            int u=v[i];
            if (deep[u]+1==deep[now]&&remain[i]){
                has_find=true;
                cur[now]=i;
                last[u]=i;
                now=u;
                break;
            }
        }

        //没有找到出边，重新进行标号
        if (!has_find){
            int minn=n-1;
            for (int i=point[now];i!=-1;i=next[i])
              if (remain[i])
                minn=min(minn,deep[v[i]]);
            //GAP优化
            if (!(--num[deep[now]])) break;
            num[deep[now]=minn+1]++;
            cur[now]=point[now];
            if (now!=s)
              now=v[last[now]^1];
        }
    }
}

int main(){
    tot=-1;
    memset(point,-1,sizeof(point));
    memset(next,-1,sizeof(next));

    scanf("%d%d",&m,&n);
    for (int i=1;i<=m;++i){
        scanf("%d%d%d",&x,&y,&cap);
        add(x,y,cap);
    }

    isap(1,n);
    printf("%d\n",maxflow);
}
