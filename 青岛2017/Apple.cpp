#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long double eps = 1e-20;
int T;
struct Point{
    long double x;
    long double y;
}pt[4];
struct Traingle{
    struct Point p[3];
};
struct Circle{
    struct Point center;
    long double r;
}ans;
//计算两点距离
long double Dis(struct Point p, struct Point q){
    long double dx=p.x-q.x;
    long double dy=p.y-q.y;
    return sqrt(dx*dx+dy*dy);
}
//计算三角形面积
long double Area(struct Traingle ct){
    return fabs((ct.p[1].x-ct.p[0].x)*(ct.p[2].y-ct.p[0].y)-(ct.p[2].x-ct.p[0].x)*(ct.p[1].y-ct.p[0].y))/2.0;
}
//求三角形的外接圆，返回圆心和半径(存在结构体"圆"中)
struct Circle CircumCircle(struct Traingle t){
    struct Circle tmp;
    long double a, b, c, c1, c2;
    long double xA, yA, xB, yB, xC, yC;
    a = Dis(t.p[0], t.p[1]);
    b = Dis(t.p[1], t.p[2]);
    c = Dis(t.p[2], t.p[0]);
    //根据S = a * b * c / R / 4;求半径R
    tmp.r = (a*b*c)/(Area(t)*4.0);
    xA = t.p[0].x;
    yA = t.p[0].y;
    xB = t.p[1].x;
    yB = t.p[1].y;
    xC = t.p[2].x;
    yC = t.p[2].y;
    c1 = (xA*xA+yA*yA - xB*xB-yB*yB) / 2;
    c2 = (xA*xA+yA*yA - xC*xC-yC*yC) / 2;
    tmp.center.x = (c1*(yA - yC)-c2*(yA - yB)) / ((xA - xB)*(yA - yC)-(xA - xC)*(yA - yB));
    tmp.center.y = (c1*(xA - xC)-c2*(xA - xB)) / ((yA - yB)*(xA - xC)-(yA - yC)*(xA - xB));
    return tmp;
}
int main(){
    scanf("%d", &T);
    while(T--){
        cin>>pt[1].x>>pt[1].y>> pt[2].x>> pt[2].y>> pt[3].x>> pt[3].y>> pt[0].x>> pt[0].y;
        cout<<pt[1].x<<' '<<pt[1].y<<' '<<pt[2].x<<' '<<pt[2].y<<' '<<pt[3].x<<' '<<pt[3].y<<' '<<pt[0].x<<' '<<pt[0].y<<endl;
        struct Traingle t;
        t.p[0] = pt[1];
        t.p[1] = pt[2];
        t.p[2] = pt[3];
        struct Circle tmp = CircumCircle(t);
        if(Dis(tmp.center, pt[0]) - tmp.r > eps){
            printf("Accepted\n");
        }
        else{
            printf("Rejected\n");
        }
    }
    return 0;
}
