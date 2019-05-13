#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define eps 1e-8
using namespace std;
const int maxn = 107;
int T, n;
struct POINT{
    double x, y;
    POINT(){};
    POINT(double x, double y):x(x), y(y){};
};
struct LINE{
    POINT a, b;
    LINE(){};
    LINE(POINT x, POINT y):a(x), b(y){};
}line[maxn];
double xmult(POINT p1, POINT p2, POINT p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
double distance(double x1,double y1,double x2,double y2){   //判断两点是否可缩为一点
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
bool opposite_side(POINT p1, POINT p2, LINE l){
    if(xmult(l.a,p1,l.b)*xmult(l.a,p2,l.b)>eps)
        return false;
    return true;
}
bool solve(POINT a, POINT b){
    if(distance(a.x, a.y, b.x, b.y) < eps){
        return false;
    }
    for(int k = 0; k < n; k++){
        if(!opposite_side(line[k].a, line[k].b, LINE(a,b))){
            return false;
        }
    }
    return true;
}
int main(){
    double x_1, x_2, y_1, y_2;
    scanf("%d", &T);
    while(T--){
        int flag = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%lf%lf%lf%lf", &x_1, &y_1, &x_2, &y_2);
            line[i] = LINE(POINT(x_1, y_1), POINT(x_2, y_2));
        }
        if(n==1){
            printf("Yes!\n");
            continue;
        }
        for(int i = 0; i < n&&!flag; i++){
            for(int j = i + 1; j < n&&!flag; j++){
                if(solve(line[i].a, line[j].a)||solve(line[i].b, line[j].a)||solve(line[i].a, line[j].b)||solve(line[i].b, line[j].b)){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag){
            printf("Yes!\n");
        }
        else{
            printf("No!\n");
        }
    }
    return 0;
}
