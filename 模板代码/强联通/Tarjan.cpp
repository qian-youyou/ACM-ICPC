#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
const int inf = 0x3f3f3f3f;
int n, m;
int head[maxn], cnt, top, dfs_num, col_num;
int dfn[maxn], low[maxn], Stack[maxn], color[maxn];
bool vis[maxn];
struct EDGE{
    int next, to, u;
}edge[maxn<<3];
void add(int u, int v){
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].u = u;
    head[u] = cnt++;
}
void Tarjan(int x){
    dfn[x] = ++dfs_num;
    low[x] = dfs_num;
    vis[x] = true;  //�Ƿ���ջ��
    Stack[++top] = x;
    for(int i = head[x]; i != -1; i = edge[i].next){
        int v = edge[i].to;
        if(!dfn[v]){
            Tarjan(v);
            low[x] = min(low[x], low[v]);
        }
        else if(vis[v]){
            low[x] = min(low[x], dfn[v]);
        }
    }
    if(dfn[x] == low[x]){   //����ǿ��ͨ����
        vis[x] = false;
        color[x] = ++col_num;   //Ⱦɫ
        while(Stack[top] != x){ //���
            color[Stack[top]] = col_num;
            vis [ Stack[ top-- ] ] = false ;
        }
        top--;
    }
}
void init(){
    top = dfs_num = col_num = cnt = 0;
    memset(head, -1, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(color, 0, sizeof(color));
    memset(vis, false, sizeof(vis));
}
void read(){
    int u, v;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &u, &v);
        add(u, v);
    }
}
void solve(){
    for(int i = 1; i <= n; i++){
        if(!color[i]){
            Tarjan(i);
        }
    }
    if(col_num != 1){
        printf("No\n");
    }
    else{
        printf("Yes\n");
    }
}
int main(){
    while(~scanf("%d%d", &n, &m) && n+m){
        init();
        read();
        solve();
    }
    return 0;
}
