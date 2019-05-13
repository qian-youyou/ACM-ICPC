#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn = 5007;
int n, m, cnt[maxn];
double  x_1, y_1, x_2, y_2;
struct Point{
    double x, y;
    Point(){};
    Point(double x, double y):x(x), y(y) {};
}point[maxn];
struct Line{
    Point a, b;
    Line(){};
    Line(Point a, Point b):a(a), b(b) {};
}line[maxn];
double X_cross(Point p1, Point p2, Point p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int half_serch(Point p){
    int i;
    for(i = 1; i<=n;i++){
        if(X_cross(line[i].a, line[i].b, p) < 0){
            break;
        }
    }
    return i-1;
}
void read(){
    double x, y;
    memset(cnt, 0, sizeof(cnt));
    Point aa = Point(x_1, y_1);
    Point bb = Point(x_1, y_2);
    line[0] = Line(aa, bb);
    for(int i = 1; i <= n; i++){
        scanf("%lf%lf", &x, &y);
        Point a = Point(x, y_1);
        Point b = Point(y, y_2);
        line[i] = Line(a, b);
    }
    for(int i = 1; i <= m; i++){
        scanf("%lf%lf", &x, &y);
        Point p0 = Point(x, y);
        ++cnt[half_serch(p0)];
    }
    for(int i = 0; i <= n; i++){
        printf("%d: %d\n", i, cnt[i]);
    }
}
int main(){
    int cas = 0;
    while(~scanf("%d", &n)&&n){
        scanf("%d%lf%lf%lf%lf", &m, &x_1, &y_1, &x_2, &y_2);
        if(cas++){
            printf("\n");
        }
        read();
    }
    return 0;
}
