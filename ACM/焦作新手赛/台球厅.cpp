#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f; //无穷大
const int maxn = 60007;
const int maxm = 1000007;
int vis[maxn],d[maxn],pre[maxn],a[maxn],m,n;    //是否访问，最短路，前置节点，流量，边集，点集
char mp[107][107];  //台球地图
struct Edge{
    int u, v, c, cost, next;
}edge[maxm];    //网络流边集

int s[maxn], cnt;   //每个点流量

void init(){    //初始化
	cnt = 0;
	memset(s, -1, sizeof(s));
}

void add(int u, int v, int c, int cost){    //对两点之间进行单向边建立
	edge[cnt].u = u;
	edge[cnt].v = v;
	edge[cnt].cost = cost;
	edge[cnt].c = c;
	edge[cnt].next = s[u];
	s[u] = cnt++;   //建立单向边
	edge[cnt].u = v;
	edge[cnt].v = u;
	edge[cnt].cost = -cost;
	edge[cnt].c = 0;
	edge[cnt].next = s[v];
	s[v] = cnt++;   //建立双向边
}

bool spfa(int ss, int ee,int &flow,int &cost){  //以距离为费用寻找最短路，以最短路为当前增广路
	queue<int> q;
	memset(d, INF, sizeof d);
	memset(vis, 0, sizeof vis); //初始化
	d[ss] = 0, vis[ss] = 1, pre[ss] = 0, a[ss] = INF;
	q.push(ss);
	while (!q.empty()){ //spfa以费用为距离寻找最短路
		int u = q.front();q.pop();
		vis[u] = 0;
		for (int i = s[u]; ~i; i = edge[i].next){   //和当前点相连所有边松弛过程
			int v = edge[i].v;
			if (edge[i].c>0&& d[v]>d[u] + edge[i].cost){    //松弛过程
				d[v] = d[u] + edge[i].cost;
				pre[v] = i;
				a[v] = min(a[u], edge[i].c);    //取最小值
				if (!vis[v]){
					vis[v] = 1;
					q.push(v);     //压入待松弛队列
				}
			}
		}
	}
	if (d[ee] == INF) return 0; //判断是否有最短路，无说明最大流完成
	flow += a[ee];
	cost += d[ee]*a[ee];
	int u = ee;
	while (u != ss){    //求当前最短路下的流量和
		edge[pre[u]].c -= a[ee];
		edge[pre[u] ^ 1].c += a[ee];
		u = edge[pre[u]].u;
	}
	return 1;
}

int MCMF(int ss, int ee){   //最小费用最大流
	int cost = 0, flow=0;   //初始化
	while (spfa(ss, ee, flow, cost));   //寻找增广路径，直到没有增广路径为止
	return cost;    //返回最大流费用
}

struct point{
    int x,y;    //球坐标，洞坐标
};

void solve(){
    point H[107],P[107];    //建立球集与洞集
    int h=0,p=0;
    for(int i=0;i<n;i++){   //输入地图
        scanf("%s",&mp[i]);
        for(int j=0;j<m;j++){
            if(mp[i][j]=='#'){  //若为洞则坐标加入洞集
                H[h].x=i;
                H[h].y=j;
                h++;
            }
            else if(mp[i][j]=='@'){ //若为球则坐标加入球集
                P[p].x=i;
                P[p].y=j;
                p++;
            }
        }
    }
    init(); //初始化
    for(int i=0;i<h;i++)
        for(int j=0;j<p;j++){
        int c=fabs(H[i].x-P[j].x)+fabs(H[i].y-P[j].y);
             add(i+1,h+j+1,1,c);
        }   //建立球与洞之间的路径
    for(int i=0;i<h;i++)    //建立超级源点
        add(0,i+1,1,0);
    for(int i=0;i<p;i++)    //建立超级汇点
        add(h+1+i,h+p+1,1,0);
    printf("%d\n",MCMF(0,h+p+1));   //最小费用最大流
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        if(!(m||n))
            break;
        solve();    //解决方案
    }
	return 0;
}
