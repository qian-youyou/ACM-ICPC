#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 407;
struct Node{
    int c;
    int f;
};
int sx,ex;
int pre[maxn];
Node Map[maxn][maxn];
int n,N,F,D;
void add(int a, int b, int c){
    Map[a][b].c += c;
}
void init(){
    sx = 0;
    ex = 2 * N + F + D + 1;
    n = 2 * N + F + D + 1;
    memset(Map,0,sizeof(Map));
    for(int i = 2 * N + 1; i <= 2 * N + F; i++){
        add(sx, i, 1);
    }
    for(int i = 2 * N + F + 1; i < n; i++){
        add(i, ex, 1);
    }
        for(int i = 1; i <= N; i++){
        add(i, i + N, 1);
    }
}
bool BFS(){
    memset(pre,0,sizeof(pre));
    queue<int>q;
    q.push(sx);
    pre[sx] = 1;
    while(!q.empty()){
        int d = q.front();
        q.pop();
        for(int i = 1;i<=n;i++){
            if(!pre[i]&&Map[d][i].c-Map[d][i].f){
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
    for(int i = 1; i <= n; i++){
        if(Map[pos][i].c - Map[pos][i].f && pre[pos] + 1 == pre[i]){
            int a = Map[pos][i].c - Map[pos][i].f;
            int t = dfs(i, min(a, flow));
            Map[pos][i].f += t;
            Map[i][pos].f -= t;
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
void read(int cur){
    int a[maxn], tmp, FF, DD;
    scanf("%d%d",&FF, &DD);
    for(int i = 0; i < FF; i++){
        scanf("%d",&a[i]);
        a[i] += 2 * N;
        add(a[i], cur, 1);
    }
    for(int i = 0; i < DD; i++){
        scanf("%d",&tmp);
        tmp += 2 * N + F;
        for(int j = 0; j < FF; j++){
            add(cur + N, tmp, 1);
        }
    }
}
int main(){
    while(~scanf("%d%d%d",&N,&F,&D)){
        init();
        for(int i = 1; i<=N; i++)
            read(i);
        printf("%d\n",dinic());
    }
    return 0;
}
