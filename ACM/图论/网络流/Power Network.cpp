#include<iostream>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+7;
const int inf = 0x3f3f3f3f;
int n, m, np, nc, sx, ex, cnt;
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
    memset(head, -1, sizeof(head));
    cnt = 0;
}
void read(){
	int a, b, d;
	sx = 0;
	ex = n+1;
	while(m--){
		scanf(" (%d,%d)%d", &a, &b, &d);
		add(a+1, b+1, d);
	}
	while(np--){
		scanf(" (%d)%d", &b, &d);
		add(0, b+1, d);
	}
	while(nc--){
		scanf(" (%d)%d", &a, &d);
		add(a+1, n+1, d);
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
    while(~scanf("%d%d%d%d",&n, &np, &nc, &m)){
        init();
        read();
        printf("%d\n", Dinic(sx, ex));
    }
    return 0;
}
