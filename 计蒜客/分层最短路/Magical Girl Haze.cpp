#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxx = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5+7;
int t,n,m,k,cnt;
ll dis[maxn][12];
bool vis[maxn][12];
int head[maxn];
struct EDGE{
    int next;
    int to;
    ll w;
}edge[2*maxn];
struct NODE{
    int u, j;
    ll dis;
    NODE(){}
	NODE(int u,int j,ll w):u(u),j(j),dis(w){}
	bool operator <(const NODE &a)const
	{
		return dis>a.dis;
	}
}node[2*maxn];
void add(int u, int v, ll w){
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    head[u] = cnt;
    cnt++;
}
void dijkstra(int s){
    memset(dis,maxx,sizeof(dis));
    memset(vis,false,sizeof(vis));
    priority_queue<NODE>q;
    q.push(NODE(s,0,0));
    while(!q.empty()){
        int kk = q.top().u;
        int j = q.top().j;
        ll minD = q.top().dis;
        q.pop();
        if(vis[kk][j])
            continue;
        vis[kk][j] = true;
        for(int l = head[kk]; l!=-1; l=edge[l].next){
            if(j<k&&!vis[edge[l].to][j+1]&&dis[edge[l].to][j+1] > minD){
                dis[edge[l].to][j+1] = minD;
                q.push(NODE(edge[l].to,j+1,dis[edge[l].to][j+1]));
            }
            if(!vis[edge[l].to][j]&&minD + edge[l].w < dis[edge[l].to][j]){
                dis[edge[l].to][j] = minD + edge[l].w;
                q.push(NODE(edge[l].to,j,dis[edge[l].to][j]));
            }
        }
    }
}
int main(){
    ll u,v,w;
    scanf("%d",&t);
    while(t--){
        memset(head,-1,sizeof(head));
        cnt = 0;
        scanf("%d%d%d",&n,&m,&k);
        for(int i = 0;i < m; i++){
            scanf("%d%d%lld",&u,&v,&w);
            add(u,v,w);
        }
        dijkstra(1);
        if(dis[n][k]!=maxx)
        	printf("%lld\n",dis[n][k]);
        else
            printf("0\n");
    }
    return 0;
}
