#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxm = 20;
const int maxn = 1e5+7;
const double eps = 1e-8;
int n;
struct EDGE{
    int u, next, to;
    double w;
}edge[maxn];
int head[maxn], cnt;
double dis[maxn];
bool vis[maxn];
double distance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}
struct NODE{
    int u;
    double dis;
    NODE(){}
    NODE(int x, int y) : u(x), dis(y){}
    bool operator <(const NODE &a)const{
		return dis>a.dis;
	}
};
void add(int u, int v, double w){
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].u = u;
    head[u] = cnt++;
}
void init(){
    cnt = 0;
    memset(head, -1, sizeof(head));
}
double dijkstra(int sx, int ex){
    memset(vis, false, sizeof(vis));
    for(int i = 0; i < 10*n; i++){
        dis[i] = 1e9*1.0;
    }
    dis[sx] = 0;
    priority_queue<NODE>que;
    que.push(NODE(sx, 0));
    while(!que.empty()){
        NODE tmp = que.top();
        que.pop();
        int kk = tmp.u;
        if(vis[kk]){
            continue;
        }
        vis[kk] = true;
        for(int i = head[kk]; i != -1; i = edge[i].next){
            int v = edge[i].to;
            if(!vis[v] && dis[kk] + edge[i].w < dis[v]){
                dis[v] = dis[kk] + edge[i].w;
                que.push(NODE(v, dis[v]));
            }
        }
    }
    return dis[ex];
}
struct point{
    double x, y;
    point(){};
    point(double x, double y):x(x),y(y){};
};
struct line{
    point a, b;
};
double xmult(point p1,point p2,point p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int opposite_side(point p1,point p2,point l1,point l2){
    return xmult(l1,p1,l2)*xmult(l1,p2,l2)<eps;
}
struct Wall{
    double x;
    double y[4];
}wall[maxm];
bool cmp(Wall a, Wall b){
    return a.x < b.x;
}
bool check(point a, point b, int st, int cur){
    for(int i = st; i<cur; i++){
        point c1 = point(wall[i].x, wall[i].y[0]);
        point c2 = point(wall[i].x, wall[i].y[1]);
        point c3 = point(wall[i].x, wall[i].y[2]);
        point c4 = point(wall[i].x, wall[i].y[3]);
        if(opposite_side(c1, c2, a, b)||opposite_side(c3, c4, a, b)){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}
double solve(){
    int SS = 0, TT = n*4+1;
    point sx = point(0, 5);
    point ex = point(10, 5);
    if(check(sx, ex, 0, n)){
        return 10;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            if(fabs(distance(wall[i].x, wall[i].y[j], wall[i].x, wall[i].y[j^1]))<eps){
                continue;
            }
            point tmp = point(wall[i].x, wall[i].y[j]);
            if(check(sx, tmp, 0, i)){
                add(SS, i*4+j+1, distance(sx.x, sx.y, tmp.x, tmp.y));
            }
            if(check(ex, tmp, i+1, n)){
                add(i*4+j+1, TT, distance(ex.x, ex.y, tmp.x, tmp.y));
            }
            for(int k = 0; k < i; k++){
                for(int kk = 0; kk < 4; kk++){
                    point tmp2 = point(wall[k].x, wall[k].y[kk]);
                    if(check(tmp2, tmp, k + 1, i)){
                        add(k*4+kk+1, i*4+j+1, distance(tmp2.x, tmp2.y, tmp.x, tmp.y));
                    }
                }
            }
        }
    }
    return dijkstra(SS, TT);
}
int main(){
    while(~scanf("%d", &n) && n != -1){
        for(int i = 0; i < n; i++){
            scanf("%lf", &wall[i].x);
            scanf("%lf%lf%lf%lf", &wall[i].y[0], &wall[i].y[1], &wall[i].y[2], &wall[i].y[3]);
            sort(wall[i].y, wall[i].y+4);
        }
        init();
        sort(wall, wall + n, cmp);
        printf("%.2lf\n", solve());
    }
    return 0;
}
