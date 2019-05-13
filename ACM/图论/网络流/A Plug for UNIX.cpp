#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 507;
struct Node{
    int c;
    int f;
};
int n,m,k,cnt;
int sx,ex;
int pre[maxn];
Node Map[maxn][maxn];
void init(){
    ex = 1;
    sx = 0;
    cnt = 1;
    memset(Map,0,sizeof(Map));
}
void add(int a, int b, int c){
    Map[a][b].c+=c;
    if(Map[a][b].c>inf)
        Map[a][b].c=inf;
}
void read(){
    map<string,int>p;
    p.clear();
    string tmp,tmp2;
    for(int i = 0; i<n; i++){
        cin>>tmp;
        if(!p[tmp]){
            p[tmp] = ++cnt;
            add(p[tmp],ex,1);
        }
        else{
            add(p[tmp],ex,1);
        }
    }
    scanf("%d",&m);
    for(int i = 0;i<m;i++){
        cin>>tmp2>>tmp;
        p[tmp2] = ++cnt;
        add(sx, p[tmp2], 1);
        if(p[tmp]){
            add(p[tmp2], p[tmp], 1);
        }
        else{
            p[tmp] = ++cnt;
            add(p[tmp2],p[tmp],1);

        }
    }
    scanf("%d",&k);
    for(int i = 0;i<k;i++){
        cin>>tmp>>tmp2;
        if(!p[tmp])
            p[tmp] = ++cnt;
        if(!p[tmp2])
            p[tmp2] = ++cnt;
        add(p[tmp],p[tmp2],inf);
    }
    n = cnt;
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
int main(){
    while(~scanf("%d",&n)){
        init();
        read();
        printf("%d\n",m-dinic());
    }
    return 0;
}
