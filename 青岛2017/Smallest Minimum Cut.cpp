#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+7;
const int inf = 0x3f3f3f3f;
int n, m, sx, ex, cnt;
int head[maxn], pre[maxn], cur[maxn];
struct EDGE{
    int u, next, to, c;
}edge[maxn<<3];
void add_edge(int u, int v, int c){
    edge[cnt].u = u;
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].c = c<=inf ? c : inf;
    head[u] = cnt++;
}
void add(int u, int v, int c){
    add_edge(u, v, c);
    add_edge(v, u, 0);//˫�������Ϊc
}
void init(){
    //memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    cnt = 0;
}
void read(){
    scanf("%d%d", &sx, &ex);
    for(int i = 0; i < m; i++){
        int u, v, w;
        scanf("%d%d%d",&u, &v, &w);
        add(u, v, w * (m + 1) + 1);
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
    for(int& i = cur[pos]; i != -1; i = edge[i].next){
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
        memcpy(cur, head, sizeof(head));
        flow += DFS(sx, inf);
    }
    return flow;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d",&n, &m);
        init();
        read();
        /*Dinic(sx, ex);
        int tmp = cnt;
        cnt = 0;
        memset(head, -1, sizeof(head));
        for(int i = 0; i < tmp; i+=2){
            if(edge[i].c == 0){
                add(edge[i].u, edge[i].to, 1);
            }
            else{
                add(edge[i].u, edge[i].to, inf);
            }
        }*/
        printf("%d\n", Dinic(sx, ex)%(m+1));
    }
    return 0;
}
