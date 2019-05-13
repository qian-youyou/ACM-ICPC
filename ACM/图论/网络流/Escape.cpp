#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e6+7;
const int inf = 0x3f3f3f3f;
int n, m, sx, ex, cnt;
int head[maxn], pre[maxn], ctn[maxn];
struct EDGE{
    int u, next, to, c;
}edge[maxn<<2];
void add_edge(int u, int v, int c){
    edge[cnt].u = u;
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].c = c<=inf ? c : inf;
    head[u] = cnt++;
}
void add(int u, int v, int c){
    add_edge(u, v, c);
    add_edge(v, u, 0);//Ë«Ïò±ßÈÝÁ¿Îªc
}
void init(){
    //memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    cnt = 0;
}
void read(){
    memset(ctn,0,sizeof(ctn));
    sx = 0, ex = 1024 + 11;
    int w;
    for(int i = 1; i <= n; i++){
        int cur = 0;
        for(int j = 0;j < m;j++){
            scanf("%d",&w);
            if(w){
                cur+=(1<<j);
            }
        }
        ctn[cur]++;
    }
    for(int i=1;i<=(1<<m);i++){
        if(ctn[i]){
            add(sx,i,ctn[i]);
            for(int j=0;j<m;j++){
                if(i&(1<<j))
                 add(i,j+ex+1,inf);
            }
        }
    }
    for(int i = 1;i<=m;i++){
        scanf("%d",&w);
        add(ex+i,ex,w);
    }
}
bool BFS(int sx, int ex){
    memset(pre, 0, sizeof(pre));
    queue<int>que;
    que.push(sx);
    pre[sx] = 1;
    while(!que.empty()){
        int kk = que.front();
        que.pop();
        for(int i = head[kk]; i != -1; i = edge[i].next){
                int v = edge[i].to;
            if(!pre[v]&&edge[i].c){
                pre[v] = pre[kk] + 1;
                que.push(v);
            }
        }
    }
    return pre[ex] != 0;
}
int DFS(int pos, int flow){
    if(pos == ex || flow == 0)
        return flow;
    int f = flow;
    for(int i = head[pos]; i != -1; i = edge[i].next){
        int tmp, v = edge[i].to;
        if(edge[i].c && pre[pos] + 1 == pre[v] && (tmp = DFS(v, min(edge[i].c, flow)))>0){
            edge[i].c -= tmp;
            edge[i^1].c += tmp;
            flow -= tmp;
            if(flow == 0){
                break;
            }
        }
    }
    return f - flow;
}
int Dinic(int sx, int ex){
    int flow = 0;
    while(BFS(sx, ex)){
        flow += DFS(sx, inf);
    }
    return flow;
}
void solve(){
    int flow = Dinic(sx, ex);
    if(flow<n)
        printf("NO\n");
    else
        printf("YES\n");
}
int main(){
    while(~scanf("%d%d",&n, &m)){
        init();
        read();
        solve();
    }
    return 0;
}
