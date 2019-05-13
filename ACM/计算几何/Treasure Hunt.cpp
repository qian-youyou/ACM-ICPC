#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 32;
int n;
struct point{
    double x, y;
    point(){};
    point(double x, double y):x(x), y(y){};
}sx;
bool operator !=(point a, point b){
    return(a.x!=b.x||a.y!=b.y);
}
bool operator ==(point a, point b){
    return(a.x==b.x&&a.y==b.y);
}
struct line{
    point a, b;
}LL[maxn];
double xmult(point p1, point p2, point p0){
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
    while(~scanf("%d", &n)){
        int cnt = n;
        for(int i = 0; i < n; i++){
            scanf("%lf%lf%lf%lf", &LL[i].a.x, &LL[i].a.y,  &LL[i].b.x, &LL[i].b.y);
        }
        scanf("%lf%lf", &sx.x, &sx.y);
        for(int i = 0; i < n; i++){
            point a = LL[i].a;
            point b = LL[i].b;
            int cnt1 = 0, cnt2 = 0;
            for(int j = 0; j < n; j++){
                point c = LL[j].a;
                point d = LL[j].b;
                if(isIntersected(sx, a, c, d)){
                    cnt1++;
                }
                if(isIntersected(sx, b, c, d)){
                    cnt2++;
                }
            }
            cnt = min(min(cnt2, cnt1), cnt);
        }
        printf("Number of doors = %d\n", cnt+1);
    }
    return 0;
}
