#include<bits/stdc++.h>
using namespace std;
const int maxn = 12;
int n,m;
int a[maxn];
double c[maxn],tmp[maxn];
int f(int n){
    int i,s=1;
    for(i=1; i<=n; i++)
        s=s*i;
    return s;
}
void init(){
    memset(c,0,sizeof(c));
    memset(tmp,0,sizeof(tmp));
    int i,j,k;
    for(i = 0;i<=a[0];i++){
        c[i] = 1.0/f(i);
    }
    for(i = 1;i<n;i++){
        if(a[i]){
            for(j = 0;j<maxn;j++){
                for(k = 0;k+j<maxn&&k<=a[i];k++)
                    tmp[k+j]+=c[j]/f(k);
            }
            for(j = 0;j<maxn;j++){
                c[j]=tmp[j];
                tmp[j]=0;
            }
        }
    }
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i = 0;i<n;i++)
            scanf("%d",&a[i]);
        init();
        printf("%.lf\n",c[m]*f(m));
    }
    return 0;
}
