#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
struct point{
    double x;
    double y;
    point(){};
    point(double x, double y):x(x),y(y){};
};
struct line{
    point a, b;
}LL;
double multi(point p0, point p1, point p2){
    return ( p1.x - p0.x )*( p2.y - p0.y )-( p2.x - p0.x )*( p1.y - p0.y );
}
bool isIntersected(point s1,point e1, point s2,point e2){
    return  (max(s1.x,e1.x) >= min(s2.x,e2.x))  &&
            (max(s2.x,e2.x) >= min(s1.x,e1.x))  &&
            (max(s1.y,e1.y) >= min(s2.y,e2.y))  &&
            (max(s2.y,e2.y) >= min(s1.y,e1.y))  &&
            (multi(s1,s2,e1)*multi(s1,e1,e2)>=0) &&
            (multi(s2,s1,e2)*multi(s2,e2,e1)>=0);
}
bool _in(point p0, point aa, point dd){
    if(p0.x>=aa.x&&p0.x<=dd.x&&p0.y>=aa.y&&p0.y<=dd.y){
        return true;
    }
    return false;
}
int main(){
    scanf("%d", &n);
    while(n--){
        int flag = 0;
        scanf("%lf%lf%lf%lf", &LL.a.x, &LL.a.y, &LL.b.x, &LL.b.y);
        double x_1, y_1, x_2, y_2;
        scanf("%lf%lf%lf%lf", &x_1, &y_1, &x_2, &y_2);
        point aa = point(min(x_1, x_2), min(y_1, y_2));
        point bb = point(min(x_1, x_2), max(y_1, y_2));
        point cc = point(max(x_1, x_2), min(y_1, y_2));
        point dd = point(max(x_1, x_2), max(y_1, y_2));
        if(_in(LL.a, aa, dd)||_in(LL.b, aa, dd)){
            flag = 1;
        }
        if(isIntersected(LL.a, LL.b, aa, dd)||isIntersected(LL.a, LL.b, bb, cc)){
            flag = 1;
        }
        if(flag){
            printf("T\n");
        }
        else{
            printf("F\n");
        }
    }
    return 0;
}
