#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxx = 0x3f3f3f3f;
const int maxn = 1e5+7;
int t,n,m,cnt;
int dis[maxn];  //当前该点到原点最短距离
bool vis[maxn]; //是否访问过
int head[maxn]; //点集
struct EDGE{
    int next,to,w,l,r;  //上一条边，下一个点，权值，左值，右值
}edge[2*maxn];  //边集
struct NODE{
    int u,dis;
    NODE(){}
	NODE(int u,ll w):u(u),dis(w){}
	bool operator <(const NODE &a)const{
		return dis>a.dis;
	}
}node[2*maxn];  //点集加最短距离
void add(int u, int v, int w, int l,int r){ //构建边集
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].l = l;
    edge[cnt].r = r;
    head[u] = cnt;
    cnt++;
}
void init(){    //初始化
    cnt = 0;
    memset(head,-1,sizeof(head));
    memset(dis,maxx,sizeof(dis));
    memset(vis,false,sizeof(vis));
}
void read(){    //读入数据
    int u,v,w,l,r;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < m; i++){
        scanf("%d%d%d%d%d",&u,&v,&w,&l,&r);
        add(u,v,w,l,r);
        add(v,u,w,l,r);
    }
}
void init_data(int kk){ //初始化数据
    vis[kk] = false;
    dis[kk] = maxx;
}
int solve(int s){
    priority_queue<NODE>q;  //储存最短距离
    q.push(NODE(s,0));  //读入原点
    while(!q.empty()){  //队列为空则无法到达
        int kk = q.top().u; //储存当前最短距离下标
        int minD = q.top().dis; //储存当前最短距离
        q.pop();
        if(kk==n)   //若下标为目标值，return
            return minD;
        vis[kk] = true; //该点是否访问
        for(int l = head[kk]; l!=-1; l=edge[l].next){   //松弛边
            if(!vis[edge[l].to]&&minD<=edge[l].r&&minD>=edge[l].l&&minD + edge[l].w < dis[edge[l].to]){
                dis[edge[l].to] = minD + edge[l].w;
                q.push(NODE(edge[l].to,dis[edge[l].to]));   //将松弛后的边压入队列
            }
        }
        init_data(kk);  //初始化数据
    }
    return 0;
}
int main(){
    scanf("%d",&t);
    while(t--){
        init(); //初始化
        read(); //读入
        printf("%d\n",solve(1));    //解决方案
    }
    return 0;
}
