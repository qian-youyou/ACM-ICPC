#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN 200
#define MAXM 10000+10
#define INF 0x3f3f3f3f
using namespace std;
struct Edge
{
    int from, to, cap, flow, cost, next;
};
Edge edge[MAXM];
int head[MAXN], edgenum;
int dist[MAXN], pre[MAXN];
bool vis[MAXN];
int source, sink;//����Դ�� �������
int N, M, K;//N������ M���ֿ� K��ʳƷ
int need[60][60];//need[i][j] ��i�������Ե�j����Ʒ������
int have[60][60];//have[i][j] ��i���ֿ����j����Ʒ�Ĵ��
int Sneed[60];//Sneed[i] ��i����Ʒ��������
int Shave[60];//Shave[i] ��i����Ʒ���ܴ��
int used[60][60];//�ڵ�k�������� �洢i�ֿ⵽j�����Ļ���
bool flag;//�ж��ܷ���������������
void init()
{
    edgenum = 0;
    memset(head, -1, sizeof(head));
}
void addEdge(int u, int v, int w, int c)
{
    Edge E1 = {u, v, w, 0, c, head[u]};
    edge[edgenum] = E1;
    head[u] = edgenum++;
    Edge E2 = {v, u, 0, 0, -c, head[v]};
    edge[edgenum] = E2;
    head[v] = edgenum++;
}
bool SPFA(int s, int t)
{
    queue<int> Q;
    memset(dist, INF, sizeof(dist));
    memset(vis, false, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    dist[s] = 0;
    vis[s] = true;
    Q.push(s);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        vis[u] = false;
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            Edge E = edge[i];
            if(dist[E.to] > dist[u] + E.cost && E.cap > E.flow)
            {
                dist[E.to] = dist[u] + E.cost;
                pre[E.to] = i;
                if(!vis[E.to])
                {
                    vis[E.to] = true;
                    Q.push(E.to);
                }
            }
        }
    }
    return pre[t] != -1;
}
void MCMF(int s, int t, int &cost, int &flow)
{
    cost = flow = 0;
    while(SPFA(s, t))
    {
        int Min = INF;
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to])
        {
            Edge E = edge[i];
            Min = min(Min, E.cap-E.flow);
        }
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to])
        {
            edge[i].flow += Min;
            edge[i^1].flow -= Min;
            cost += edge[i].cost * Min;
        }
        flow += Min;
    }
}
void solve()
{
    memset(Sneed, 0, sizeof(Sneed));
    memset(Shave, 0, sizeof(Shave));
    for(int i = 1; i <= N; i++)//��������
    {
        for(int j = 1; j <= K; j++)//��ÿ����Ʒ������
        {
            scanf("%d", &need[i][j]);
            Sneed[j] += need[i][j];
        }
    }
    for(int i = 1; i <= M; i++)//ÿ���ֿ�
    {
        for(int j = 1; j <= K; j++)//ÿ����Ʒ ���
        {
            scanf("%d", &have[i][j]);
            Shave[j] += have[i][j];
        }
    }
    flag = true;
    for(int i = 1; i <= K; i++)
    {
        if(Shave[i] < Sneed[i])//��� ��������
        {
            flag = false;
            break;
        }
    }
    int ans = 0;//�����
    int cost, flow;
    for(int k = 1; k <= K; k++)//K������  ��K����Ʒ������� ��Ϊÿ���ⶼ�Ƕ�����
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= M; j++)
                scanf("%d", &used[i][j]);//��j���ֿ����͵�k����Ʒ����i�������������
        }
        if(!flag) continue;//�Ѿ��жϳ� ������������
        init();
        source = 0, sink = N+M+1;
        for(int i = 1; i <= N; i++)//���� �򳬼���㽨��
            addEdge(i, sink, need[i][k], 0);
        for(int i = 1; i <= M; i++)//����Դ�� ��ֿ⽨��
            addEdge(source, i+N, have[i][k], 0);
        for(int i = 1; i <= M; i++)
        {
            for(int j = 1; j <= N; j++)
                addEdge(i+N, j, INF, used[j][i]);//�ֿ� �� ÿ����������
        }
        MCMF(source, sink, cost, flow);
        if(flow != Sneed[k])//������������ ��k����Ʒ��������
            flag = false;//������
        else
            ans += cost;//�ۼ� ÿ�εĽ��
    }
    if(flag)
        printf("%d\n", ans);
    else
        printf("-1\n");
}
int main()
{
    while(scanf("%d%d%d", &N, &M, &K), N||M||K)
    {
        solve();
    }
    return 0;
}
/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn = 107;
const int inf = 0x3f3f3f3f;
struct EDGE{
    int c;
    int w;
}edge[57][maxn][maxn];
int n, m, k, sx, ex, num, N;
int cnt, dis[maxn], pre[maxn], st[57], et[57];
bool vis[maxn];
void add(int k, int u, int v, int c, int w){
    edge[k][u][v].c += c;
    if(edge[k][u][v].c > inf){
        edge[k][u][v].c = inf;
    }
    edge[k][u][v].w += w;
}
void init(){
    sx = 0;
    ex = n+m+1;
    memset(edge, 0, sizeof(edge));
    memset(st, 0, sizeof(st));
    memset(et, 0, sizeof(et));
    N = ex;
}
void read(){
    int tmp;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            scanf("%d",&tmp);
            st[j]+=tmp;
            add(j,i,ex,tmp,0);
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= k; j++){
            scanf("%d",&tmp);
            et[j]+=tmp;
            add(j,sx,n+i,tmp,0);
        }
    }
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++){
            for(int e = 1; e <= m; e++){
                scanf("%d",&tmp);
                add(i,n+e,j,inf,tmp);
            }
        }
    }
}
bool SPFA(int k, int sx, int ex){
    memset(vis, false, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    memset(dis, inf, sizeof(dis));
    queue<int>que;
    que.push(sx);
    dis[sx] = 0;
    while(!que.empty()){
        int kk = que.front();
        que.pop();
        vis[kk] = false;
        for(int i = 1; i <= N; i++){
            if(edge[k][kk][i].c){
                if(dis[i]>edge[k][kk][i].w + dis[kk]){
                    dis[i] = edge[k][kk][i].w + dis[kk];
                    pre[i] = kk;
                    if(!vis[i]){
                        vis[i] = true;
                        que.push(i);
                    }
                }
            }
        }
    }
    return pre[ex]!=-1;
}
int MCMF(int k, int sx, int ex){
    int i, min_flow, flow = 0, cost = 0;
    while(SPFA(k, sx, ex)){
        min_flow = inf;
        for(i = ex; pre[i]!=-1; i = pre[i]){
            min_flow = min(edge[k][pre[i]][i].c, min_flow);
        }
        for(i = ex; pre[i]!=-1; i=pre[i]){
            edge[k][pre[i]][i].c -= min_flow;
            edge[k][i][pre[i]].c += min_flow;
        }
        cost += dis[ex] * min_flow;
        flow += min_flow;
    }
    return cost;
}
void solve(){
    int ans = 0;
    for(int i = 1;i<=k;i++){
        int cost = MCMF(i,sx, ex);
        if(et[i]<st[i]){
            printf("-1\n");
            return;
        }
        ans+=cost;
    }
    printf("%d\n",ans);
}
int main(){
    while(~scanf("%d%d%d",&n,&m,&k)){
        if(!(n+m+k))
            break;
        init();
        read();
        solve();
    }
    return 0;
}
*/
