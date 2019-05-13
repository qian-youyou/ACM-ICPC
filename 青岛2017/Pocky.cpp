#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const double eps = 1e-8;
int main(){
    int T;
    double a, b;
    scanf("%d", &T);
    while(T--){
        scanf("%lf%lf", &a, &b);
        double tmp = log(a/b);
        if(b>=a)
            tmp = 0;
        else{
            tmp+=1;
        }
        printf("%.6lf\n", tmp);
    }
    return 0;
}
