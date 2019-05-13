#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxx = 0x3f3f3f3f;
const int maxn = 1e5+7;
int t,n,m,cnt;
int dis[maxn];
bool vis[maxn];
int head[maxn];
struct EDGE{
    int next;
    int to;
    int w;
    int l;
    int r;
}edge[2*maxn];
struct NODE{
    int u;
    int dis;
    NODE(){}
	NODE(int u,ll w):u(u),dis(w){}
	bool operator <(const NODE &a)const
	{
		return dis>a.dis;
	}
}node[2*maxn];
void add(int u, int v, int w, int l,int r){
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].l = l;
    edge[cnt].r = r;
    head[u] = cnt;
    cnt++;
}
int dijkstra(int s){
    memset(dis,maxx,sizeof(dis));
    memset(vis,false,sizeof(vis));
    priority_queue<NODE>q;
    q.push(NODE(s,0));
    while(!q.empty()){
        int kk = q.top().u;
        int minD = q.top().dis;
        q.pop();
        if(kk==n)
            return minD;
        if(vis[kk])
            continue;
        vis[kk] = true;
        for(int l = head[kk]; l!=-1; l=edge[l].next){
            if(!vis[edge[l].to]&&minD<=edge[l].r&&minD>=edge[l].l&&minD + edge[l].w < dis[edge[l].to]){
                dis[edge[l].to] = minD + edge[l].w;
                q.push(NODE(edge[l].to,dis[edge[l].to]));
            }
        }
        vis[kk] = false;
        dis[kk] = maxx;
    }
    return 0;
}
int main(){
    int u,v,w,l,r;
    scanf("%d",&t);
    while(t--){
        memset(head,-1,sizeof(head));
        cnt = 0;
        scanf("%d%d",&n,&m);
        for(int i = 0;i < m; i++){
            scanf("%d%d%d%d%d",&u,&v,&w,&l,&r);
            add(u,v,w,l,r);
            add(v,u,w,l,r);
        }
        int ans = dijkstra(1);
        printf("%d\n",ans);
    }
    return 0;
}
