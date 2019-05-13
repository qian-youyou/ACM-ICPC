#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn = 5007;
int n, m, cnt[maxn], cnt_2[maxn];
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
bool cmp(Line a, Line b){
    if(a.a.x == b.a.x){
        return a.b.x < b.b.x;
    }
    return a.a.x < b.a.x;
}
double X_cross(Point p1, Point p2, Point p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int half_serch(Point p){
    int L = 0, R = n + 1, M;
    while(L < R){
        M = (L + R) / 2;
        if(L == R - 1){
            break;
        }
        if(X_cross(line[M].a, line[M].b, p) < 0){
            R = M;
        }
        else{
            L = M;
        }
    }
    return M;
}
void read(){
    int maxx = 0;
    double x, y;
    memset(cnt, 0, sizeof(cnt));
    memset(cnt_2, 0, sizeof(cnt_2));
    Point aa = Point(x_1, y_1);
    Point bb = Point(x_1, y_2);
    line[0] = Line(aa, bb);
    for(int i = 1; i <= n; i++){
        scanf("%lf%lf", &x, &y);
        Point a = Point(x, y_1);
        Point b = Point(y, y_2);
        line[i] = Line(a, b);
    }
    sort(line, line + n + 1, cmp);
    for(int i = 1; i <= m; i++){
        scanf("%lf%lf", &x, &y);
        Point p0 = Point(x, y);
        int tmp = half_serch(p0);
        cnt_2[cnt[tmp]]--;
        cnt_2[++cnt[tmp]]++;
        maxx = max(maxx, cnt_2[cnt[tmp]]);
    }
    printf("Box\n");
    for(int i = 1; i <= maxx; i++){
        if(cnt_2[i]>0){
            printf("%d: %d\n", i, cnt_2[i]);
        }
    }
}
int main(){
    while(~scanf("%d", &n)&&n){
        scanf("%d%lf%lf%lf%lf", &m, &x_1, &y_1, &x_2, &y_2);
        read();
    }
    return 0;
}
