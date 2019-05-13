#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+7;
const int inf = 0x3f3f3f3f;
int N, F, D, sx, ex, cnt;
int head[maxn], pre[maxn];
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
    add_edge(v, u, 0);//Ë«Ïò±ßÈÝÁ¿Îªc
}
void init(){
    //memset(edge, 0, sizeof(edge));
    memset(head, -1, sizeof(head));
    cnt = 0;
}
void read(){
    int w;
    char str[207];
    sx = 0, ex = 2 * N + F + D + 1;
    for(int i = 1; i <= F; i++){
        scanf("%d",&w);
        add(sx, 2 * N + i, w);
    }
    for(int i = 1; i <= D; i++){
        scanf("%d",&w);
        add(2 * N + F + i, ex, w);
    }
    for(int i = 1; i <= N; i++){
        add(i, N + i, 1);
        scanf("%s",str);
        for(int j = 0;j<F;j++){
            if(str[j]=='Y'){
                add(2 * N + j + 1, i, 1);
            }
        }
    }
    for(int i = 1; i <= N; i++){
        scanf("%s",str);
        for(int j = 0;j<D;j++){
            if(str[j]=='Y'){
                add(N + i, 2 * N + F + j + 1, 1);
            }
        }
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
int main(){
    while(~scanf("%d%d%d",&N, &F, &D)){
        init();
        read();
        printf("%d\n", Dinic(sx, ex));
    }
    return 0;
}
