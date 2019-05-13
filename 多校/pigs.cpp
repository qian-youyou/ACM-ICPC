#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=105,M=1005,INF=1e9;
inline int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0'; c=getchar();}
    return x*f;
}

int m,n,s,t;
int pig[M],now[M];
struct edge{
    int v,c,f,ne;
}e[N*M<<1];
int cnt,h[N];
inline void ins(int u,int v,int c){
    cnt++;
    e[cnt].v=v;e[cnt].c=c;e[cnt].f=0;e[cnt].ne=h[u];h[u]=cnt;
    cnt++;
    e[cnt].v=u;e[cnt].c=0;e[cnt].f=0;e[cnt].ne=h[v];h[v]=cnt;
}
int q[N],head,tail,vis[N],d[N];
bool bfs(){
    memset(vis,0,sizeof(vis));
    memset(d,0,sizeof(d));
    head=tail=1;
    d[s]=0;vis[s]=1;
    q[tail++]=s;
    while(head!=tail){
        int u=q[head++];
        for(int i=h[u];i;i=e[i].ne){
            int v=e[i].v;
            if(!vis[v]&&e[i].c>e[i].f){
                vis[v]=1;
                d[v]=d[u]+1;
                q[tail++]=v;
                if(v==t) return true;
            }
        }
    }
    return false;
}
int cur[N];
int dfs(int u,int a){
    if(u==t||a==0) return a;
    int flow=0,f;
    for(int &i=cur[u];i;i=e[i].ne){
        int v=e[i].v;
        if(d[v]==d[u]+1&&(f=dfs(v,min(a,e[i].c-e[i].f)))>0){
            flow+=f;
            e[i].f+=f;
            e[((i-1)^1)+1].f-=f;
            a-=f;
            if(a==0) break;
        }
    }
    return flow;
}
int dinic(){
    int flow=0;
    while(bfs()){
        for(int i=s;i<=t;i++) cur[i]=h[i];
        flow+=dfs(s,INF);
    }
    return flow;
}
int main(){
    //freopen("in.txt","r",stdin);
    m=read();n=read();s=0;t=n+1;
    for(int i=1;i<=m;i++) pig[i]=read();
    for(int i=1;i<=n;i++){
        int A=read(),B,x;
        while(A--){
            x=read();
            if(!now[x]) ins(s,i,pig[x]),now[x]=i;
            else ins(now[x],i,INF),now[x]=i;
        }
        B=read();
        ins(i,t,B);
    }
    printf("%d",dinic());
}
