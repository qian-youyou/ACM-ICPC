#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define MOD 100000007
using namespace std;
typedef long long ll;
struct sq{
    ll sq[2][2];
    void mes(){
        memset(sq,0,sizeof(sq));
    }
};
sq operator *(sq a,sq b){
    sq tmp;
    tmp.mes();
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                tmp.sq[i][j]=(tmp.sq[i][j]+a.sq[i][k]*b.sq[k][j])%MOD;
            }
        }
    }
    return tmp;
}
ll fi(int n,int a,int b,int c, int d){
    sq ans,m;
    ans.mes();
    m.mes();
    m.sq[0][0]=c;
    m.sq[0][1]=d;
    m.sq[1][0]=1;
    m.sq[1][1]=0;
    ans.sq[0][0]=1;
    ans.sq[1][1]=1;
    ans.sq[0][1]=ans.sq[1][0]=0;
    while(n){
        if(n&1){
            ans=ans*m;
        }
        m=m*m;
        n>>=1;
    }
    m.sq[0][0]=a;
    m.sq[0][1]=0;
    m.sq[1][0]=b;
    m.sq[1][1]=0;
    ans=ans*m;
    return ans.sq[0][0]%MOD;
}
int main(){
    int n,a,b,c,d;
    while(scanf("%d%d%d%d%d",&a,&b,&c,&d,&n))
        printf("%lld\n",fi(n,a,b,c,d));
    return 0;
}
