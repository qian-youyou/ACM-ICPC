#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
using namespace std;
int T;
double x_1, x_2, y_1, y_2, x_3, y_3, x_4, y_4;
struct point{
    double x, y;
    point(){};
    point(double x, double y):x(x),y(y){};
};
point operator - (point a, point b){
    return point(a.x-b.x, a.y-b.y);
}
struct line{
    point a, b;
    line(){};
    line(point x, point y):a(x),b(y){};
};
double xmulit(point p1, point p2, point p0){
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

point intersection(point u1,point u2,point v1,point v2){
    point ret=u1;
    double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
             /((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
    ret.x+=(u2.x-u1.x)*t;
    ret.y+=(u2.y-u1.y)*t;
    return ret;
}
int dots_inline(point p1,point p2,point p3){
    return zero(xmulit(p1,p2,p3));
}
int main(){
    scanf("%d", &T);
    printf("INTERSECTING LINES OUTPUT\n");
    while(T--){
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x_1, &y_1, &x_2, &y_2, &x_3, &y_3, &x_4, &y_4);
        line L1 = line(point(x_1,y_1), point(x_2, y_2));
        line L2 = line(point(x_3,y_3), point(x_4, y_4));
        if(fabs(xmulit(L1.a - L1.b, L2.a - L2.b, point(0,0)))<eps){
            if(!dots_inline(L1.a, L1.b, L2.b)){
                printf("NONE\n");
            }
            else{
                printf("LINE\n");
            }
        }
        else{
            point tmp = intersection(L1.a, L1.b, L2.a, L2.b);
            printf("POINT %.2lf %.2lf\n", tmp.x, tmp.y);
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
