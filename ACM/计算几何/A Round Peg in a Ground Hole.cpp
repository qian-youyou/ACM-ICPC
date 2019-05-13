#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include <math.h>
#define MAXN 1010

//offset为多变形坐标的最大绝对值
#define offset 10000
#define eps 1e-8

//浮点数判0
#define zero(x) (((x)>0?(x):-(x))<eps)

//浮点数判断符
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))

int n;
double c_r;
//定义点
struct point{
    double x,y;
}pt[MAXN], cc;

//定义线段
struct line{
    point a,b;
};

//叉积
double xmult(point p1,point p2,point p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

//判定凸多边形,顶点按顺时针或逆时针给出,允许相邻边共线,是凸多边形返回1，否则返回0
int is_convex(int n,point* p){
    int i,s[3]={1,1,1};
    for (i=0;i<n&&s[1]|s[2];i++)
        s[_sign(xmult(p[(i+1)%n],p[(i+2)%n],p[i]))]=0;
    return s[1]|s[2];
}
int inside_convex(point q,int n,point* p)
{
    int i,s[3]={1,1,1};
    for (i=0;i<n&&s[1]|s[2];i++)
        s[_sign(xmult(p[(i+1)%n],q,p[i]))]=0;
    return s[1]|s[2];
}

double distance(point p1,point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
//点到直线的距离
double disptoline(point p,point l1,point l2)
{
    return fabs(xmult(p,l1,l2))/distance(l1,l2);
}
//求两直线交点
point intersection(point u1,point u2,point v1,point v2)
{
    point ret=u1;
    double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
             /((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
    ret.x+=(u2.x-u1.x)*t;
    ret.y+=(u2.y-u1.y)*t;
    return ret;
}

int intersect_seg_circle(point c,double r, point l1,point l2)
{
    double t1=distance(c,l1)-r,t2=distance(c,l2)-r;
    point t=c;
    if (t1<eps||t2<eps)
        return t1>-eps||t2>-eps;
    t.x+=l1.y-l2.y;
    t.y+=l2.x-l1.x;
    return xmult(l1,c,t)*xmult(l2,c,t)<eps&&disptoline(c,l1,l2)-r<-eps;
}


int main(){
    while(~scanf("%d", &n)&&n>2){
        scanf("%lf%lf%lf", &c_r, &cc.x, &cc.y);
        for(int i = 0; i < n; i++){
            scanf("%lf%lf", &pt[i].x, &pt[i].y);
        }
        if(!is_convex(n, pt)){
            printf("HOLE IS ILL-FORMED\n");
        }
        else{
            if(!inside_convex(cc,n,pt)){
                printf("PEG WILL NOT FIT\n");
            }
            else{
                int i = 0;
                for(i = 0; i<n; i++){
                    if(intersect_seg_circle(cc, c_r, pt[i],pt[(i+1)%n])){
                        break;
                    }
                }
                if(i>=n){
                    printf("PEG WILL FIT\n");
                }
                else{
                    printf("PEG WILL NOT FIT\n");
                }
            }
        }
    }
    return 0;
}
