#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 307;
struct NODE{
    int c;
    int f;
};
int sx,ex;
int pre[maxn];
NODE road[maxn][maxn];
int n, m, N;
bool BFS(){
    memset(pre,0,sizeof(pre));
    queue<int>q;
    q.push(sx);
    pre[sx] = 1;
    while(!q.empty()){
        int d = q.front();
        q.pop();
        for(int i = 1;i<=N;i++){
            if(!pre[i]&&road[d][i].c-road[d][i].f){
                pre[i] = pre[d] + 1;
                q.push(i);
            }
        }
    }
    return pre[ex]!=0;
}
int dfs(int pos, int flow){
    int f = flow;
    if(pos==ex)
        return flow;
    for(int i = 1; i <= N; i++){
        if(road[pos][i].c - road[pos][i].f && pre[pos] + 1 == pre[i]){
            int a = road[pos][i].c - road[pos][i].f;
            int t = dfs(i, min(a, flow));
            road[pos][i].f += t;
            road[i][pos].f -= t;
            flow -= t;
        }
    }
    return f - flow;
}
int dinic(){
    int sum = 0;
    while(BFS()){
        sum+=dfs(sx,inf);
    }
    return sum;
}
void init(){
    N = n;
    sx = 0;
    ex = N;
    memset(road,0,sizeof(road));
}
void read(){
    int u,v,w;
    for(int i = 1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        road[u][v].c+=w;
    }
}
int main(){
    while(~scanf("%d%d",&m,&n)){
        init();
        read();
        printf("%d\n",dinic());
    }
    return 0;
}
