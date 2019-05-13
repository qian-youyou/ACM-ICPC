#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
const int maxn = 1e5+7;
int n;
bool top[maxn];
struct point{
    double x, y;
    point(){};
    point(double x, double y):x(x),y(y){};
};
struct line{
    point a, b;
}LL[maxn];
double xmult(point p1,point p2,point p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
bool isIntersected(point s1,point e1, point s2,point e2){
    return  (max(s1.x,e1.x) >= min(s2.x,e2.x))  &&
            (max(s2.x,e2.x) >= min(s1.x,e1.x))  &&
            (max(s1.y,e1.y) >= min(s2.y,e2.y))  &&
            (max(s2.y,e2.y) >= min(s1.y,e1.y))  &&
            (xmult(s1,s2,e1)*xmult(s1,e1,e2)>0) &&
            (xmult(s2,s1,e2)*xmult(s2,e2,e1)>0);
}
int main(){
    while(~scanf("%d", &n)&&n){
        queue<int>q[2];
        int flag = 0;
        memset(top, false, sizeof(top));
        for(int i = 0; i < n; i++){
            scanf("%lf%lf%lf%lf", &LL[i].a.x, &LL[i].a.y, &LL[i].b.x, &LL[i].b.y);
            if(q[flag].empty()){
                q[flag].push(i);
                while(!q[flag^1].empty()){
                    int tmp = q[flag^1].front();
                    q[flag^1].pop();
                    if(isIntersected(LL[tmp].a, LL[tmp].b, LL[i].a, LL[i].b)){
                        top[tmp] = true;
                    }
                    else{
                        q[flag].push(tmp);
                    }
                }
                flag^=1;
            }
        }
        printf("Top sticks:");
        for(int i = 0; i < n - 1; i++){
            if(!top[i]){
                printf(" %d,", i + 1);
            }
        }
        printf(" %d.\n", n);
    }
    return 0;
}
